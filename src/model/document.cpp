#include "model/document.hpp"
#include "model/document_loader.hpp"
#include <ncurses.h>


Document::Document(const std::string *url)
    :url(*url), on_loaded_callback(NULL), body(NULL)
{
    DocumentLoader::load_async(this);
}
Document::Document(const std::string *url, Helpers::Callback *on_loaded_callback)
    :url(*url), on_loaded_callback(on_loaded_callback), body(NULL)
{
    DocumentLoader::load_async(this);
}

Document::~Document()
{
    if (is_loading())
        DocumentLoader::cancel_async_loading(this);

    if (on_loaded_callback)
        delete on_loaded_callback;
}

void Document::on_loaded(GumboOutput *gdoc)
{
    // Building doc
    title = "Test title";

    // Calling external callback
    on_loaded_callback->exec();
}

const std::string *Document::get_url() const
{
    return &url;
}

const std::string *Document::get_title() const
{
    if (!is_loading())
        return &title;
    return get_url();
}

bool Document::is_loading() const
{
    return DocumentLoader::is_loading(this);
}
