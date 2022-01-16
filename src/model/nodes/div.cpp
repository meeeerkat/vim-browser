#include "model/nodes/div.hpp"


namespace Nodes {
    Div::Div(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {

    }

    void Div::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Element::printw(window, printing_options);
        if (children.size() == 0)
            return;

        if (!printing_options.is_new_line) {
            wprintw(window, "\n");
            printing_options.is_new_line = true;
        }

        Element::print_children(window, printing_options);
        
        printing_options.is_new_line = false;
    }
}

