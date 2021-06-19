#include <curl/curl.h>
#include <string.h>
#include <pthread.h>
#include "model.h"


#define HTML_BUFFER_SIZE 10000


// Private declarations
typedef struct model {
    CURL *curl;
    char curl_errbuf[CURL_ERROR_SIZE];
} model_t;

typedef struct load_page_params {
    char *url;
    page_t *page;
    void (*callback)(void*);
    void *callback_params;
} load_page_params_t;

static model_t model;

static void* load_page(load_page_params_t *params);
static uint write_page_data(lxb_char_t *chunck, uint size, uint nmemb, lxb_html_document_t *doc);



void model_init()
{
    model.curl = curl_easy_init();
    curl_easy_setopt(model.curl, CURLOPT_ERRORBUFFER, model.curl_errbuf);
    curl_easy_setopt(model.curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(model.curl, CURLOPT_VERBOSE, 0L);
    curl_easy_setopt(model.curl, CURLOPT_WRITEFUNCTION, write_page_data);
}

void model_free()
{
    curl_easy_cleanup(model.curl);
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

    curl_easy_setopt(model.curl, CURLOPT_URL, params->url);
    curl_easy_setopt(model.curl, CURLOPT_WRITEDATA, params->page->doc);
    int err = curl_easy_perform(model.curl);
    if (err) {
        //fprintf(stderr, "%s\n", model.curl_errbuf);
        return NULL;
    }
    status = lxb_html_document_parse_chunk_end(params->page->doc);

    params->callback(params->callback_params);
    free(params);
    return NULL;
}

void model_load_page_async(char *url, page_t *page, void (*callback) (void*), void *callback_params)
{
    load_page_params_t *params = malloc(sizeof(load_page_params_t));
    params->url = url;
    params->page = page;
    params->callback = callback;
    params->callback_params = callback_params;
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, (void* (*) (void*))load_page, (void*)params);
}

