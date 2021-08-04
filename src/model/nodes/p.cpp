#include "model/nodes/p.hpp"

namespace Nodes {
    P::P(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {

    }

    void P::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Element::printw(window, printing_options);
        if (children.size() == 0)
            return;

        wprintw(window, "\n");
        Element::print_children(window, printing_options);
    }
}
