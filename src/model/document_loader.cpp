#include <pthread.h>
#include <cassert>
#include <ncurses.h>
#include <unistd.h>
#include <curl/curl.h>
#include <gumbo.h>
#include <string>
#include <map>
#include <limits>
#include "model/document_loader.hpp"
#include "model/document.hpp"


namespace DocumentLoader {

    struct curl_easy_request {
        CURL *handle = NULL;
        std::string buffer = "";
    };

    namespace {
        CURLM *curl;
        //char curl_errbuf[CURL_ERROR_SIZE];
        std::map<Document*, curl_easy_request> requests;
    }
    // Executed in the main thread
    void remove_request(Document *doc);
    void add_easy_handle(Document *doc);
    // Executed in a separate thread
    uint append_to_buffer(char *chunck, uint size, uint nmemb, std::string *buffer);
    void* load_documents(void *args);

    void init()
    {
        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_multi_init();
        
        pthread_t id;
        pthread_create(&id, NULL, load_documents, NULL);
    }

    void free()
    {
        curl_multi_cleanup(curl);
        curl_global_cleanup();
    }

    void remove_request(Document *doc)
    {
        curl_multi_remove_handle(curl, requests[doc].handle);
        curl_easy_cleanup(requests[doc].handle);
        requests.erase(doc);
    }
    void add_request(Document *doc)
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

    uint append_to_buffer(char *chunck, uint size, uint nmemb, std::string *buffer)
    {
        const size_t n = size*nmemb;
        // Probably not that fast
        for (size_t i=0; i < n; i++)
            *buffer += chunck[i];
        return n;
    }
    // Loads all the requested documents
    void* load_documents(void *args)
    {
        while (true) {
            int alive_requests_nb;
            curl_multi_perform(curl, &alive_requests_nb);

            CURLMsg *msg;
            int msgs_left = -1;
            while((msg = curl_multi_info_read(curl, &msgs_left))) {
                if(msg->msg == CURLMSG_DONE) {
                    CURL *easy_handle = msg->easy_handle;
                    Document *doc;
                    curl_easy_getinfo(easy_handle, CURLINFO_PRIVATE, &doc);
                    // Parsing output
                    GumboOutput *parsed_output = gumbo_parse(requests[doc].buffer.c_str());
                    // Deleting the request
                    remove_request(doc);
                    // Calling callback (request has to be deleted first)
                    doc->on_loaded(parsed_output);
                    gumbo_destroy_output(&kGumboDefaultOptions, parsed_output);
                }
                else {
                    // TODO: Handle errors
                    assert(0);
                    return NULL;
                }
            }
            // curl_multi_poll waits the timeout if there is no handle attached
            // while curl_multi_wait just returns instantly
            // (which completly consumes the thread)
            curl_multi_poll(curl, NULL, 0, 1000, NULL);
        }

        return NULL;
    }
   
    void load_async(Document *doc)
    {
        // Documents can only load once (they are not supposed to be reused)
        if (is_loading(doc))
            return;

        // Then add a new one
        add_request(doc);
    }

    void cancel_async_loading(Document *doc)
    {
        remove_request(doc);
    }

    bool is_loading(const Document *doc)
    {
        // TODO: pretty ugly cast but can't seem to make it work any another way
        return requests.count((Document*) doc) > 0;
    }
}
