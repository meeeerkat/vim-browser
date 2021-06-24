#include "model/page.hpp"


Page::Page()
{
}

Page::~Page()
{
}


void Page::set_url(std::string url)
{
    this->url = url;
}
/*
void model_page_load(model_page_t *page, void (*callback) (void*), void *callback_params)
{
    model_loader_load_page_async(page, callback, callback_params);
}
void model_page_set_url_and_load(model_page_t *page, char *url, void (*callback) (void*), void *callback_params)
{
    model_page_set_url(page, url);
    model_page_load(page, callback, callback_params);
}
*/

std::string *Page::get_title()
{
    return NULL;
}

