#include "model/nodes/input.hpp"
#include "model/nodes/form.hpp"
#include "model/nodes/loader.hpp"


namespace Nodes {
    Input::Input(const GumboElement *el, BuildData &build_data, bool is_interactive)
        : InteractiveElement(el, build_data, is_interactive)
    {
        name = load_attribute(el, "name");
        value = load_attribute(el, "value");

        if (build_data.current_form)
            build_data.current_form->add_input(this);
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
