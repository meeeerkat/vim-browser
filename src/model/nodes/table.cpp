#include "model/nodes/table.hpp"


namespace Nodes {
    Table::Table(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {

    }

    void Table::printw(WINDOW *window, PrintingOptions &printing_options) const
    {
        Element::printw(window, printing_options);
    }
}
