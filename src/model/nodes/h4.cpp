#include "model/nodes/h4.hpp"

namespace Nodes {
    H4::H4(const GumboElement *el)
        : Element(el)
    {

    }

    void H4::printw(WINDOW *window) const
    {
        wattron(window, A_BOLD);
        Element::printw(window);
        wattroff(window, A_BOLD);
    }
}
