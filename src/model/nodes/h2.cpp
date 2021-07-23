#include "model/nodes/h2.hpp"

namespace Nodes {
    H2::H2(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {

    }

    void H2::printw(WINDOW *window, PrintingOptions &printing_options) const
    {
        wattron(window, A_BOLD);
        wprintw(window, "\n");
        Element::printw(window, printing_options);
        wattroff(window, A_BOLD);
    }
}
