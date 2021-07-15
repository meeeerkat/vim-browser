#include "model/nodes/form.hpp"

namespace Nodes {
    Form::Form(const GumboElement *el)
        : Element(el)
    {

    }

    void Form::printw(WINDOW *window) const
    {
        Element::printw(window);
    }
}
