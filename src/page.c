#include "page.h"



page_t *page_init()
{
    page_t *page = malloc(sizeof(page_t));
    page->doc = lxb_html_document_create();

    return page;
}

void page_free(page_t *page)
{
    if (page->doc)
        lxb_html_document_destroy(page->doc);
    free(page);
}
