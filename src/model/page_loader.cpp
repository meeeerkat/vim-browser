#include <pthread.h>
#include "model/page_loader.hpp"


namespace PageLoader {

    namespace {
        CURL *curl;
        char curl_errbuf[CURL_ERROR_SIZE];

        void load_page(load_page_params *params);
        //uint write_page_data(lxb_char_t *chunck, uint size, uint nmemb, lxb_html_document_t *doc);
    }

    typedef struct load_page_params {
        Page *page;
        void (*callback)(void*);
        void *callback_params;
    };


    void init()
    {
        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, curl_errbuf);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
        //curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_page_data);
    }

    void free()
    {
        curl_easy_cleanup(curl);
    }


    /*
    uint write_page_data(lxb_char_t *chunck, uint size, uint nmemb, lxb_html_document_t *doc)
    {
        size_t n = size*nmemb;
        lxb_html_document_parse_chunk(doc, chunck, n);
        return n;
    }
    */


    void load_page(load_page_params *params)
    {
        /*
        lxb_html_document_parse_chunk_begin(params->page->doc);

        curl_easy_setopt(curl, CURLOPT_URL, params->page->url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, params->page->doc);
        int err = curl_easy_perform(curl);
        if (err) {
            //fprintf(stderr, "%s\n", curl_errbuf);
            return NULL;
        }
        lxb_html_document_parse_chunk_end(params->page->doc);
        */

        params->callback(params->callback_params);
        std::free(params);
    }

    void load_async(Page *page, void (*callback) (void*), void *callback_params)
    {
        load_page_params *params = new load_page_params {
            page,
            callback,
            callback_params
        };
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void* (*) (void*))PageLoader::load_page, (void*)params);
    }
}
