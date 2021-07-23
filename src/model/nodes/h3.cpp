#include "model/nodes/h3.hpp"

namespace Nodes {
    H3::H3(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {

    }

    void H3::printw(WINDOW *window, PrintingOptions &printing_options) const
    {
        wattron(window, A_BOLD);
        wprintw(window, "\n");
        Element::printw(window, printing_options);
        wattroff(window, A_BOLD);
    }
}
