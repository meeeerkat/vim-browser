#include "model/nodes/input.hpp"
#include "model/nodes/loader.hpp"


namespace Nodes {
    Input::Input(const GumboElement *el, BuildData &build_data)
        : InteractiveElement(el, build_data)
    {
        value = Nodes::load_attribute(el, "value");
    }

    void Input::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        InteractiveElement::printw(window, printing_options);
    }

    void Input::print_id(WINDOW *window, PrintingOptions &printing_options) const
    {
        if (printing_options.interaction_type == PrintingOptions::InteractionType::Input)
            InteractiveElement::print_id(window, printing_options);
    }
    
}
