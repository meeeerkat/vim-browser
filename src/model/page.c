#include "model/page.h"
#include "model/loader.h"



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


void model_page_set_url(model_page_t *page, char *url)
{
    strcpy(page->url, url);
}
void model_page_load(model_page_t *page, void (*callback) (void*), void *callback_params)
{
    model_loader_load_page_async(page, callback, callback_params);
}
void model_page_set_url_and_load(model_page_t *page, char *url, void (*callback) (void*), void *callback_params)
{
    model_page_set_url(page, url);
    model_page_load(page, callback, callback_params);
}


