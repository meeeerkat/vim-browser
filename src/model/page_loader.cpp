#include <pthread.h>
#include <ncurses.h>
#include <unistd.h>
#include <lexbor/html/html.h>
#include <curl/curl.h>
#include "model/page_loader.hpp"


namespace PageLoader {

    namespace {
        CURL *curl;
        char curl_errbuf[CURL_ERROR_SIZE];
    }
    uint write_page_data(lxb_char_t *chunck, uint size, uint nmemb, lxb_html_document_t *doc);
    void* load_page(void *args);

    void init()
    {
        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, curl_errbuf);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_page_data);
    }

    void free()
    {
        curl_easy_cleanup(curl);
    }


    struct load_page_params {
        lxb_html_document_t *doc;
        std::string url;
        void (*callback)(void*);
        void *callback_params;
    };
    
    uint write_page_data(lxb_char_t *chunck, uint size, uint nmemb, lxb_html_document_t *doc)
    {
        size_t n = size*nmemb;
        lxb_html_document_parse_chunk(doc, chunck, n);
        return n;
    }


    void* load_page(void *args)
    {
        load_page_params *params = (load_page_params*) args;
        lxb_html_document_parse_chunk_begin(params->doc);

        curl_easy_setopt(curl, CURLOPT_URL, params->url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, params->doc);
        int err = curl_easy_perform(curl);
        if (err) {
            //fprintf(stderr, "%s\n", curl_errbuf);
            lxb_html_document_parse_chunk_end(params->doc);
            std::free(params);
            return NULL;
        }
        lxb_html_document_parse_chunk_end(params->doc);

        params->callback(params->callback_params);
        std::free(params);
        return NULL;
    }
   
    void load_async(lxb_html_document_t *doc, std::string url, void (*callback) (void*), void *callback_params)
    {
        load_page_params *params = new load_page_params {
            doc,
            url,
            callback,
            callback_params
        };
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, PageLoader::load_page, (void*) params);
    }
}
