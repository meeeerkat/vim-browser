#include "model/nodes/tr.hpp"


namespace Nodes {
    Tr::Tr(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {

    }

    void Tr::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Element::printw(window, printing_options);
        wprintw(window, "\n");
        Element::print_children(window, printing_options);
    }
}
