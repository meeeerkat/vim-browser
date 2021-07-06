#include "model/nodes/a.hpp"

namespace Nodes {
    A::A(const GumboElement *el)
        : Element(el)
    {

    }

    void A::printw(WINDOW *window) const
    {
        wattron(window, A_UNDERLINE);
        Element::printw(window);
        wattroff(window, A_UNDERLINE);
    }
}
