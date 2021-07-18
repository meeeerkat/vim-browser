#include "model/nodes/h5.hpp"

namespace Nodes {
    H5::H5(const GumboElement *el, BuildData *build_data)
        : Element(el, build_data)
    {

    }

    void H5::printw(WINDOW *window, PrintingOptions *printing_options) const
    {
        wattron(window, A_BOLD);
        wprintw(window, "\n");
        Element::printw(window, printing_options);
        wattroff(window, A_BOLD);
    }
}
