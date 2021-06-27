#include <ncurses.h>
#include "model/page.hpp"
#include "model/document_loader.hpp"


Page::Page()
{
    doc = NULL;
    state = Empty;
}

Page::~Page()
{
    if (doc)
        delete doc;
}


void Page::load(std::string url_p, void (*on_page_loaded_callback_p) (void*), void *on_page_loaded_callback_args_p)
{
    url = url_p;
    state = State::Loading;
    if (doc) {
        delete doc;
        doc = NULL;
    }
    on_page_loaded_callback = on_page_loaded_callback_p;
    on_page_loaded_callback_args = on_page_loaded_callback_args_p;

    DocumentLoader::load_async(url, (void (*) (Document*, void*)) on_page_loaded, this);
}

void Page::on_page_loaded(Document *doc, Page *page)
{
    page->doc = doc;
    page->state = State::Loaded;
    page->on_page_loaded_callback(page->on_page_loaded_callback_args);
    page->on_page_loaded_callback = NULL;
    page->on_page_loaded_callback_args = NULL;
}

const std::string *Page::get_url()
{
    return &url;
}

Document *Page::get_document()
{
    return doc;
}
