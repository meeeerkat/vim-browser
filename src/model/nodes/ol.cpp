#include "model/nodes/ol.hpp"

namespace Nodes {
    Ol::Ol(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {

    }

    void Ol::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Element::printw(window, printing_options);
        Element::print_children(window, printing_options);
    }
}
