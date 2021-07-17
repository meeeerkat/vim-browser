#include "model/nodes/td.hpp"


namespace Nodes {
    Td::Td(const GumboElement *el)
        : Element(el)
    {

    }

    void Td::printw(WINDOW *window) const
    {
        Element::printw(window);
    }
}
