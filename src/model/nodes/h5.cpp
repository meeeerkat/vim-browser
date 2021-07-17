#include "model/nodes/h5.hpp"

namespace Nodes {
    H5::H5(const GumboElement *el)
        : Element(el)
    {

    }

    void H5::printw(WINDOW *window) const
    {
        wattron(window, A_BOLD);
        wprintw(window, "\n");
        Element::printw(window);
        wattroff(window, A_BOLD);
    }
}
