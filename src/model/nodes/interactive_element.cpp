#include "model/nodes/interactive_element.hpp"


namespace Nodes {
    InteractiveElement::InteractiveElement(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {
        id = build_data.interactive_elements.size();
        build_data.interactive_elements.push_back(this);
    }

    InteractiveElement::~InteractiveElement()
    {
    }

    void InteractiveElement::print_id(WINDOW *window, PrintingOptions &printing_options) const
    {
        attron(A_ITALIC);
        wprintw(window, "{%d}", id);
        attroff(A_ITALIC);
    }

    void InteractiveElement::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Element::printw(window, printing_options);
    }
}
