#ifndef __PAGE_H__
#define __PAGE_H__

#include <lexbor/html/html.h>


// public structure to hold each page data
typedef struct page {
    lxb_html_document_t *doc;
} page_t;


page_t *page_init();
void page_free(page_t *page);

#endif
