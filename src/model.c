#include <curl/curl.h>
#include <string.h>
#include "model.h"


#define HTML_BUFFER_SIZE 10000


typedef struct model {
    CURL *curl;
    char curl_errbuf[CURL_ERROR_SIZE];
} model_t;

static model_t model;


uint write_cb(lxb_char_t *chunck, uint size, uint nmemb, lxb_html_document_t *doc)
{
    size_t n = size*nmemb;
    lxb_html_document_parse_chunk(doc, chunck, n);
    return n;
}
 

void model_init()
{
    model.curl = curl_easy_init();
    curl_easy_setopt(model.curl, CURLOPT_ERRORBUFFER, model.curl_errbuf);
    curl_easy_setopt(model.curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(model.curl, CURLOPT_VERBOSE, 0L);
    curl_easy_setopt(model.curl, CURLOPT_WRITEFUNCTION, write_cb);
}

int8_t model_load_page(char *url, page_t *page)
{
    lxb_status_t status = lxb_html_document_parse_chunk_begin(page->doc);

    curl_easy_setopt(model.curl, CURLOPT_URL, url);
    curl_easy_setopt(model.curl, CURLOPT_WRITEDATA, page->doc);
    int err = curl_easy_perform(model.curl);
    if (err) {
        //fprintf(stderr, "%s\n", model.curl_errbuf);
        return -1;
    }
    status = lxb_html_document_parse_chunk_end(page->doc);

    return 0;
}


void model_free()
{
    curl_easy_cleanup(model.curl);
}

