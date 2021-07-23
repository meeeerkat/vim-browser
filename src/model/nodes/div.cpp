#include "model/nodes/div.hpp"


namespace Nodes {
    Div::Div(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {

    }

    void Div::printw(WINDOW *window, PrintingOptions &printing_options) const
    {
        if (children.size() == 0)
            return;

        wprintw(window, "\n");
        Element::printw(window, printing_options);
    }
}

