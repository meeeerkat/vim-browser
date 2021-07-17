#include "model/nodes/div.hpp"


namespace Nodes {
    Div::Div(const GumboElement *el)
        : Element(el)
    {

    }

    void Div::printw(WINDOW *window) const
    {
        wprintw(window, "\n");
        Element::printw(window);
        wprintw(window, "\n");
    }
}

