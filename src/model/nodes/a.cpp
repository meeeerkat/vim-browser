#include "model/nodes/a.hpp"

namespace Nodes {
    A::A(const GumboElement *el, BuildData *build_data)
        : InteractiveElement(el, build_data)
    {
    }

    void A::printw(WINDOW *window, PrintingOptions *printing_options) const
    {
        wattron(window, A_UNDERLINE);
        Element::printw(window, printing_options);
        wattroff(window, A_UNDERLINE);

        InteractiveElement::printw(window, printing_options);
    }
}
