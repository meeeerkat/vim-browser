#include <cassert>
#include <iostream>
#include "model/document.hpp"
#include "model/document_loader.hpp"
#include "model/nodes/text.hpp"
#include "helpers/url.hpp"



Document::Document(const Helpers::HttpRequest &request, DocumentLoader *loader)
    :request(request), loader(loader), on_loaded_callback(NULL), body(NULL)
{
    build_data.base_url = Helpers::Url::get_base(request.url);
    loader->load_async(this);
}
Document::Document(const Helpers::HttpRequest &request, DocumentLoader *loader, Helpers::Callback *on_loaded_callback)
    :request(request), loader(loader), on_loaded_callback(on_loaded_callback), body(NULL)
{
    build_data.base_url = Helpers::Url::get_base(request.url);
    loader->load_async(this);
}

Document::~Document()
{
    if (is_loading())
        loader->cancel_async_loading(this);

    if (on_loaded_callback)
        delete on_loaded_callback;

    if (body)
        delete body;
}

void Document::parse_title(GumboElement *title_element)
{
    title = "";
    if (title_element->children.length != 1)
        return;
    GumboNode *title_text = static_cast<GumboNode*>(title_element->children.data[0]);
    if (title_text->type != GUMBO_NODE_TEXT && title_text->type != GUMBO_NODE_WHITESPACE)
        return;
    title = title_text->v.text.text;
}

void Document::parse_head(GumboElement *head)
{
    GumboVector* head_children = &head->children;
    for (size_t i=0; i < head_children->length; ++i) {
        GumboNode* child = static_cast<GumboNode*>(head_children->data[i]);
        if (child->type == GUMBO_NODE_ELEMENT) {
            if (child->v.element.tag == GUMBO_TAG_TITLE)
                parse_title(&child->v.element);
            // else if(...)
        }
    }
}

void Document::on_loaded(GumboOutput *gdoc)
{
    // Reading header to build doc data
    GumboNode *root = gdoc->root;
    assert(root->type == GUMBO_NODE_ELEMENT);
    assert(root->v.element.children.length >= 2);

    // Getting head and body GumboNode(s)
    GumboElement *gumbo_head = NULL;
    GumboElement *gumbo_body = NULL;
    const GumboVector* root_children = &root->v.element.children;
    for (size_t i=0; i < root_children->length; ++i) {
        GumboNode* child = static_cast<GumboNode*>(root_children->data[i]);
        if (child->type == GUMBO_NODE_ELEMENT) {
            if (child->v.element.tag == GUMBO_TAG_HEAD)
                gumbo_head = &child->v.element;
            else if (child->v.element.tag == GUMBO_TAG_BODY)
                gumbo_body = &child->v.element;
        }
    }
    assert(gumbo_head != NULL);
    assert(gumbo_body != NULL);

    // Parsing head
    parse_head(gumbo_head);

    // Building body
    body = new Nodes::Body(gumbo_body, build_data);

    // Calling external callback
    on_loaded_callback->exec();
}

void Document::on_loading_failed(const std::string &error)
{
    body = new Nodes::Body(build_data);
    std::string error_msg = std::string(error);
    Nodes::Text *error_text_node = new Nodes::Text(error_msg, build_data);
    body->children.push_back(error_text_node);

    // Calling external callback
    on_loaded_callback->exec();
}

const Helpers::HttpRequest &Document::get_request() const
{
    return request;
}

const std::string &Document::get_title() const
{
    if (!title.empty())
        return title;
    return get_request().url;
}

bool Document::is_loading() const
{
    return loader->is_loading(this);
}

void Document::printw(WINDOW *window, Nodes::PrintingOptions printing_options) const
{
    if (is_loading())
        return;

    body->printw(window, printing_options);
    if (printing_options.cursor_y >= 0 && printing_options.cursor_x >= 0)
        wmove(window, printing_options.cursor_y, printing_options.cursor_x);
}

Nodes::InteractiveElement *Document::get_interactive_element(const std::string &id)
{
    uint32_t el_index;
    try {
        el_index = std::stoi(id);
    } catch (const std::invalid_argument &e) {
        return NULL;
    }

    if (el_index < build_data.interactive_elements.size())
        return build_data.interactive_elements[el_index];
    return NULL;
}
