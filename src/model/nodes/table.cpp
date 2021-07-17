#include "model/nodes/table.hpp"


namespace Nodes {
    Table::Table(const GumboElement *el)
        : Element(el)
    {

    }

    void Table::printw(WINDOW *window) const
    {
        Element::printw(window);
    }
}
