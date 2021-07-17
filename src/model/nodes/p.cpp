#include "model/nodes/p.hpp"

namespace Nodes {
    P::P(const GumboElement *el)
        : Element(el)
    {

    }

    void P::printw(WINDOW *window) const
    {
        if (children.size() == 0)
            return;

        wprintw(window, "\n");
        Element::printw(window);
    }
}
