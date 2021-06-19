#ifndef __MODEL_PAGE_H__
#define __MODEL_PAGE_H__

#include <lexbor/html/html.h>


// public structure to hold each page data
typedef struct model_page {
    lxb_html_document_t *doc;
} model_page_t;


model_page_t *model_page_init();
void model_page_free(model_page_t *page);

#endif
