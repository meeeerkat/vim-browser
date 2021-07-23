#include "model/nodes/h6.hpp"

namespace Nodes {
    H6::H6(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {

    }

    void H6::printw(WINDOW *window, PrintingOptions &printing_options) const
    {
        wattron(window, A_BOLD);
        wprintw(window, "\n");
        Element::printw(window, printing_options);
        wattroff(window, A_BOLD);
    }
}
