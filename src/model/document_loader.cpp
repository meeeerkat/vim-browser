#include <pthread.h>
#include <iostream>
#include <cassert>
#include <unistd.h>
#include <limits>
#include "model/document_loader.hpp"
#include "model/document.hpp"


DocumentLoader::DocumentLoader()
{
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_multi_init();
    
    pthread_create(&thread_id, NULL, load_documents, this);
}

DocumentLoader::~DocumentLoader()
{
    pthread_cancel(thread_id);
    curl_multi_cleanup(curl);
    curl_global_cleanup();
}

void DocumentLoader::remove_request(Document *doc)
{
    curl_multi_remove_handle(curl, requests[doc].handle);
    curl_easy_cleanup(requests[doc].handle);
    requests.erase(doc);
}
void DocumentLoader::add_request(Document *doc)
{
    requests[doc] = {};

    CURL *handle = curl_easy_init();
    curl_easy_setopt(handle, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(handle, CURLOPT_VERBOSE, 0L);
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, append_to_buffer);
    curl_easy_setopt(handle, CURLOPT_URL, doc->get_url().c_str());
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &(requests[doc].buffer));
    curl_easy_setopt(handle, CURLOPT_PRIVATE, doc);

    curl_multi_add_handle(curl, handle);
    requests[doc].handle = handle;
}

uint DocumentLoader::append_to_buffer(char *chunck, uint size, uint nmemb, std::string *buffer)
{
    const size_t n = size*nmemb;
    // Probably not that fast
    for (size_t i=0; i < n; i++)
        *buffer += chunck[i];
    return n;
}
// Loads all the requested documents
void *DocumentLoader::load_documents(void *args)
{
    DocumentLoader *loader = static_cast<DocumentLoader*>(args);

    while (true) {
        int alive_requests_nb;
        curl_multi_perform(loader->curl, &alive_requests_nb);

        CURLMsg *msg;
        int msgs_left = -1;
        while((msg = curl_multi_info_read(loader->curl, &msgs_left))) {
            if(msg->msg == CURLMSG_DONE) {
                CURL *easy_handle = msg->easy_handle;
                Document *doc;
                curl_easy_getinfo(easy_handle, CURLINFO_PRIVATE, &doc);
                // Parsing output
                GumboOutput *parsed_output = gumbo_parse(loader->requests[doc].buffer.c_str());
                // Deleting the request
                loader->remove_request(doc);
                // Calling callback (request has to be deleted first)
                doc->on_loaded(parsed_output);
                gumbo_destroy_output(&kGumboDefaultOptions, parsed_output);
            }
            else {
                // TODO: Handle errors
                assert(false);
                return NULL;
            }
        }
        // curl_multi_poll waits the timeout if there is no handle attached
        // while curl_multi_wait just returns instantly
        // (which completly consumes the thread)
        curl_multi_poll(loader->curl, NULL, 0, 1000, NULL);
    }

    return NULL;
}

void DocumentLoader::load_async(Document *doc)
{
    // Documents can only load once (they are not supposed to be reused)
    if (is_loading(doc))
        return;

    // Then add a new one
    add_request(doc);
}

void DocumentLoader::cancel_async_loading(Document *doc)
{
    remove_request(doc);
}

bool DocumentLoader::is_loading(const Document *doc) const
{
    // TODO: pretty ugly cast but can't seem to make it work any another way
    return requests.count((Document*) doc) > 0;
}
