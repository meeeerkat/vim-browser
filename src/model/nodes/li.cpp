#include "model/nodes/li.hpp"

namespace Nodes {
    Li::Li(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {

    }

    void Li::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Element::printw(window, printing_options);

        wprintw(window, "\n");
        Element::print_children(window, printing_options);
    }
}
