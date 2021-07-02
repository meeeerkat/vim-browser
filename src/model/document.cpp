#include "model/document.hpp"
#include "model/document_loader.hpp"


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
    if (!title.empty())
        return &title;
    return get_url();
}
