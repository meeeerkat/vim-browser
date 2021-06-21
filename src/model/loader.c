#include <curl/curl.h>
#include <string.h>
#include <pthread.h>
#include "model/loader.h"


#define HTML_BUFFER_SIZE 10000


// Private declarations
typedef struct model_loader {
    CURL *curl;
    char curl_errbuf[CURL_ERROR_SIZE];
} model_loader_t;

typedef struct load_page_params {
    char *url;
    model_page_t *page;
    void (*callback)(void*);
    void *callback_params;
} load_page_params_t;

static model_loader_t model_loader;

static void* load_page(load_page_params_t *params);
static uint write_page_data(lxb_char_t *chunck, uint size, uint nmemb, lxb_html_document_t *doc);



void model_loader_init()
{
    model_loader.curl = curl_easy_init();
    curl_easy_setopt(model_loader.curl, CURLOPT_ERRORBUFFER, model_loader.curl_errbuf);
    curl_easy_setopt(model_loader.curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(model_loader.curl, CURLOPT_VERBOSE, 0L);
    curl_easy_setopt(model_loader.curl, CURLOPT_WRITEFUNCTION, write_page_data);
}

void model_loader_free()
{
    curl_easy_cleanup(model_loader.curl);
}


uint write_page_data(lxb_char_t *chunck, uint size, uint nmemb, lxb_html_document_t *doc)
{
    size_t n = size*nmemb;
    lxb_html_document_parse_chunk(doc, chunck, n);
    return n;
}


void* load_page(load_page_params_t *params)
{
    lxb_status_t status = lxb_html_document_parse_chunk_begin(params->page->doc);

    curl_easy_setopt(model_loader.curl, CURLOPT_URL, params->page->url);
    curl_easy_setopt(model_loader.curl, CURLOPT_WRITEDATA, params->page->doc);
    int err = curl_easy_perform(model_loader.curl);
    if (err) {
        //fprintf(stderr, "%s\n", model_loader.curl_errbuf);
        return NULL;
    }
    status = lxb_html_document_parse_chunk_end(params->page->doc);

    params->callback(params->callback_params);
    free(params);
    return NULL;
}

void model_loader_load_page_async(model_page_t *page, void (*callback) (void*), void *callback_params)
{
    load_page_params_t *params = malloc(sizeof(load_page_params_t));
    params->page = page;
    params->callback = callback;
    params->callback_params = callback_params;
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, (void* (*) (void*))load_page, (void*)params);
}

