#include "model/nodes/h6.hpp"

namespace Nodes {
    H6::H6(const GumboElement *el)
        : Element(el)
    {

    }

    void H6::printw(WINDOW *window) const
    {
        wattron(window, A_BOLD);
        Element::printw(window);
        wattroff(window, A_BOLD);
    }
}
