#include "model/nodes/div.hpp"


namespace Nodes {
    Div::Div(const GumboElement *el)
        : Element(el)
    {

    }

    void Div::printw(WINDOW *window) const
    {
        if (children.size() == 0)
            return;

        wprintw(window, "\n");
        Element::printw(window);
    }
}

