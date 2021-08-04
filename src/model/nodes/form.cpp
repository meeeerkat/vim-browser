#include "model/nodes/form.hpp"

namespace Nodes {
    Form::Form(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {

    }

    void Form::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Element::printw(window, printing_options);
        Element::print_children(window, printing_options);
    }
}
