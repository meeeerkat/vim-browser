#include "model/page.h"



model_page_t *model_page_init()
{
    model_page_t *page = malloc(sizeof(model_page_t));
    page->doc = lxb_html_document_create();

    return page;
}

void model_page_free(model_page_t *page)
{
    if (page->doc)
        lxb_html_document_destroy(page->doc);
    free(page);
}
