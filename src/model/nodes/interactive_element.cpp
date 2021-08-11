#include "model/nodes/interactive_element.hpp"


namespace Nodes {
    InteractiveElement::InteractiveElement(const GumboElement *el, BuildData &build_data, bool is_interactive)
        : Element(el, build_data)
    {
        if (is_interactive) {
            id = build_data.interactive_elements.size();
            build_data.interactive_elements.push_back(this);
        }
    }

    InteractiveElement::~InteractiveElement()
    {
    }

    void InteractiveElement::print_id(WINDOW *window, PrintingOptions &printing_options) const
    {
        if (printing_options.interaction_type == PrintingOptions::InteractionType::None)
            return;

        attron(A_ITALIC);
        wprintw(window, "{%d}", id);
        attroff(A_ITALIC);
    }
}
