#include "model/nodes/input.hpp"
#include "model/nodes/form.hpp"
#include "model/nodes/loader.hpp"


namespace Nodes {
    Input::Input(const GumboElement *el, BuildData &build_data)
        : InteractiveElement(el, build_data)
    {
        name = load_attribute(el, "name");
        value = load_attribute(el, "value");

        if (build_data.current_form)
            build_data.current_form->add_input(this);
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

    std::string Input::get_name() const
    {
        return name;
    }
    
    std::string Input::get_value() const
    {
        return value;
    }
    
}
