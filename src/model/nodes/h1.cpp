#include "model/nodes/h1.hpp"

namespace Nodes {
    H1::H1(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {

    }

    void H1::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Element::printw(window, printing_options);
        wattron(window, A_BOLD);
        if (!printing_options.is_new_line) {
            wprintw(window, "\n");
            printing_options.is_new_line = true;
        }
        Element::print_children(window, printing_options);
        printing_options.is_new_line = false;
        wattroff(window, A_BOLD);
    }
}
