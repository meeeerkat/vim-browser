#ifndef __MODEL_PAGE_H__
#define __MODEL_PAGE_H__

#include <lexbor/html/html.h>

#define URL_MAX_LENGTH 5000
#define TITLE_MAX_LENGTH 100


// public structure to hold each page data
typedef struct model_page {
    char url[URL_MAX_LENGTH];
    const char *title;
    lxb_html_document_t *doc;
} model_page_t;


model_page_t *model_page_init();
void model_page_free(model_page_t *page);
void model_page_set_url(model_page_t *page, char *url);
void model_page_load(model_page_t *page, void (*callback) (void*), void *callback_params);
void model_page_set_url_and_load(model_page_t *page, char *url, void (*callback) (void*), void *callback_params);
const char *model_page_get_title(model_page_t *page);

#endif
