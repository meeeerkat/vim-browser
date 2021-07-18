#include "model/nodes/h1.hpp"

namespace Nodes {
    H1::H1(const GumboElement *el, BuildData *build_data)
        : Element(el, build_data)
    {

    }

    void H1::printw(WINDOW *window, PrintingOptions *printing_options) const
    {
        wattron(window, A_BOLD);
        wprintw(window, "\n");
        Element::printw(window, printing_options);
        wattroff(window, A_BOLD);
    }
}
