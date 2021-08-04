#include "model/nodes/td.hpp"


namespace Nodes {
    Td::Td(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {

    }

    void Td::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Element::printw(window, printing_options);
        Element::print_children(window, printing_options);
    }
}
