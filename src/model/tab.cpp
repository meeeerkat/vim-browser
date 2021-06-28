#include <ncurses.h>
#include "model/tab.hpp"
#include "model/document_loader.hpp"


Tab::Tab()
{
    doc = NULL;
    state = Empty;
}

Tab::~Tab()
{
    if (doc)
        delete doc;
}


void Tab::load(std::string url_p, void (*on_tab_loaded_callback_p) (void*), void *on_tab_loaded_callback_args_p)
{
    url = url_p;
    state = State::Loading;
    if (doc) {
        delete doc;
        doc = NULL;
    }
    on_tab_loaded_callback = on_tab_loaded_callback_p;
    on_tab_loaded_callback_args = on_tab_loaded_callback_args_p;

    DocumentLoader::load_async(url, (void (*) (Document*, void*)) on_tab_loaded, this);
}

void Tab::on_tab_loaded(Document *doc, Tab *tab)
{
    tab->doc = doc;
    tab->state = State::Loaded;
    tab->on_tab_loaded_callback(tab->on_tab_loaded_callback_args);
    tab->on_tab_loaded_callback = NULL;
    tab->on_tab_loaded_callback_args = NULL;
}

const std::string *Tab::get_url()
{
    return &url;
}

Document *Tab::get_document()
{
    return doc;
}
