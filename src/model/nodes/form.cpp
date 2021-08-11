#include "model/nodes/form.hpp"

namespace Nodes {
    Form::Form(const GumboElement *el, BuildData &build_data)
        : Element(build_data)
    {
        // Forms aren't supposed to be nested so build_data.current_form is supposed to be nullptr here
        build_data.current_form = this;
        Element::setup_children(el, build_data);
        build_data.current_form = nullptr;
    }

    void Form::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Element::printw(window, printing_options);
        Element::print_children(window, printing_options);
    }
    
    void Form::send()
    {

    }

}
