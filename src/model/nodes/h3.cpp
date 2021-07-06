#include "model/nodes/h3.hpp"

namespace Nodes {
    H3::H3(const GumboElement *el)
        : Element(el)
    {

    }

    void H3::printw(WINDOW *window) const
    {
        wattron(window, A_BOLD);
        Element::printw(window);
        wattroff(window, A_BOLD);
    }
}
