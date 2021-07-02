#include <pthread.h>
#include <ncurses.h>
#include <unistd.h>
#include <curl/curl.h>
#include <gumbo.h>
#include <string>
#include "model/document_loader.hpp"
#include "model/document.hpp"


namespace DocumentLoader {

    namespace {
        CURL *curl;
        char curl_errbuf[CURL_ERROR_SIZE];
    }
    uint append_to_buffer(char *chunck, uint size, uint nmemb, std::string *buffer);
    void* load_doc(void *args);

    void init()
    {
        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, curl_errbuf);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, append_to_buffer);
    }

    void free()
    {
        curl_global_cleanup();
        curl_easy_cleanup(curl);
    }


    uint append_to_buffer(char *chunck, uint size, uint nmemb, std::string *buffer)
    {
        const size_t n = size*nmemb;
        // Probably not that fast
        for (size_t i=0; i < n; i++)
            *buffer += chunck[i];
        return n;
    }

    void* load_doc(void *arg)
    {
        Document *doc = (Document*) arg;
        std::string buffer;

        curl_easy_setopt(curl, CURLOPT_URL, doc->get_url()->c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        int err = curl_easy_perform(curl);
        if (err) {
            //fprintf(stderr, "%s\n", curl_errbuf);
            return NULL;
        }

        GumboOutput *parsed_output = gumbo_parse(buffer.c_str());
        doc->on_loaded(parsed_output);
        gumbo_destroy_output(&kGumboDefaultOptions, parsed_output);

        return NULL;
    }
   
    void load_async(Document *doc)
    {
        pthread_t id;
        pthread_create(&id, NULL, load_doc, doc);
    }
}
