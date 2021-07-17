#include "model/nodes/h1.hpp"

namespace Nodes {
    H1::H1(const GumboElement *el)
        : Element(el)
    {

    }

    void H1::printw(WINDOW *window) const
    {
        wattron(window, A_BOLD);
        wprintw(window, "\n");
        Element::printw(window);
        wattroff(window, A_BOLD);
    }
}
