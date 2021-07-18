#include "model/nodes/tr.hpp"


namespace Nodes {
    Tr::Tr(const GumboElement *el, BuildData *build_data)
        : Element(el, build_data)
    {

    }

    void Tr::printw(WINDOW *window, PrintingOptions *printing_options) const
    {
        wprintw(window, "\n");
        Element::printw(window, printing_options);
    }
}
