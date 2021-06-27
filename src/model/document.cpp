#include "model/document.hpp"


Document::Document(const std::string *source)
{
    title = "Test title";
}

Document::~Document()
{

}

const std::string *Document::get_title() const
{
    return &title;
}
