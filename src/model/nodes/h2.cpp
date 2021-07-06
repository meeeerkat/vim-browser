#include "model/nodes/h2.hpp"

namespace Nodes {
    H2::H2(const GumboElement *el)
        : Element(el)
    {

    }

    void H2::printw(WINDOW *window) const
    {
        wattron(window, A_BOLD);
        Element::printw(window);
        wattroff(window, A_BOLD);
    }
}
