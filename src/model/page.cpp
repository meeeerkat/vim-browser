#include "model/page.hpp"
#include <ncurses.h>


Page::Page()
{
    doc = lxb_html_document_create();
}

Page::~Page()
{
    lxb_html_document_destroy(doc);
}


void Page::set_url(std::string url)
{
    this->url = url;
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

