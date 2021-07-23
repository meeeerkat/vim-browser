#include "model/nodes/interactive_element.hpp"


namespace Nodes {
    InteractiveElement::InteractiveElement(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {
        id = build_data.interactive_elements.size();
        build_data.interactive_elements.push_back(this);
    }

    void InteractiveElement::printw(WINDOW *window, PrintingOptions &printing_options) const
    {
        if (!printing_options.show_interactions)
            return;

        attron(A_ITALIC);
        wprintw(window, "{%d}", id);
        attroff(A_ITALIC);
    }
}
