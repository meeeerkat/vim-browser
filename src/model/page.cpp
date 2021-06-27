#include "model/page.hpp"
#include "model/page_loader.hpp"
#include <ncurses.h>


Page::Page()
{
    doc = lxb_html_document_create();
    state = State::Empty;
}

Page::~Page()
{
    lxb_html_document_destroy(doc);
}


void Page::load(std::string url_p, void (*on_page_loaded_callback_p) (void*), void *on_page_loaded_callback_args_p)
{
    url = url_p;
    state = State::Loading;
    on_page_loaded_callback = on_page_loaded_callback_p;
    on_page_loaded_callback_args = on_page_loaded_callback_args_p;

    PageLoader::load_async(doc, url, (void (*) (void*)) on_page_loaded, this);
}

void Page::on_page_loaded(Page *page)
{
    page->state = State::Loaded;
    page->on_page_loaded_callback(page->on_page_loaded_callback_args);
    page->on_page_loaded_callback = NULL;
    page->on_page_loaded_callback_args = NULL;
}

const std::string *Page::get_url()
{
    return &url;
}

char *Page::get_title()
{
    size_t title_len;
    return (char *) lxb_html_document_title(doc, &title_len);
}

