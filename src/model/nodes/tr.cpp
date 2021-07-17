#include "model/nodes/tr.hpp"


namespace Nodes {
    Tr::Tr(const GumboElement *el)
        : Element(el)
    {

    }

    void Tr::printw(WINDOW *window) const
    {
        wprintw(window, "\n");
        Element::printw(window);
    }
}
