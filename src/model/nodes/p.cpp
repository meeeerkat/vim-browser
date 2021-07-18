#include "model/nodes/p.hpp"

namespace Nodes {
    P::P(const GumboElement *el, BuildData *build_data)
        : Element(el, build_data)
    {

    }

    void P::printw(WINDOW *window, PrintingOptions *printing_options) const
    {
        if (children.size() == 0)
            return;

        wprintw(window, "\n");
        Element::printw(window, printing_options);
    }
}
