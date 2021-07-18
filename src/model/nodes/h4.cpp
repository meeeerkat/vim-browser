#include "model/nodes/h4.hpp"

namespace Nodes {
    H4::H4(const GumboElement *el, BuildData *build_data)
        : Element(el, build_data)
    {

    }

    void H4::printw(WINDOW *window, PrintingOptions *printing_options) const
    {
        wattron(window, A_BOLD);
        wprintw(window, "\n");
        Element::printw(window, printing_options);
        wattroff(window, A_BOLD);
    }
}
