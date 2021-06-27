#include <pthread.h>
#include <ncurses.h>
#include <unistd.h>
#include <curl/curl.h>
#include <gumbo.h>
#include <string>
#include "model/document_loader.hpp"


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


    struct load_document_params {
        std::string url;
        void (*callback) (Document*, void*);
        void *callback_params;
    };
    
    uint append_to_buffer(char *chunck, uint size, uint nmemb, std::string *buffer)
    {
        const size_t n = size*nmemb;
        // Probably not that fast
        for (size_t i=0; i < n; i++)
            *buffer += chunck[i];
        return n;
    }

    void* load_doc(void *args)
    {
        load_document_params *params = (load_document_params*) args;
        std::string buffer;

        curl_easy_setopt(curl, CURLOPT_URL, params->url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        int err = curl_easy_perform(curl);
        if (err) {
            //fprintf(stderr, "%s\n", curl_errbuf);
            mvprintw(4,4,"%s", curl_errbuf);
            refresh();
            std::free(params);
            return NULL;
        }

        params->callback(new Document(&buffer), params->callback_params);
        std::free(params);
        return NULL;
    }
   
    void load_async(std::string url, void (*callback) (Document*, void*), void *callback_params)
    {
        load_document_params *params = new load_document_params {
            url,
            callback,
            callback_params
        };
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, DocumentLoader::load_doc, (void*) params);
    }
}
