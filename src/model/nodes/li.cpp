#include "model/nodes/li.hpp"

namespace Nodes {
    Li::Li(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {

    }

    void Li::printw(WINDOW *window, PrintingOptions &printing_options) const
    {
        wprintw(window, "\n");
        Element::printw(window, printing_options);
    }
}
