#include "model/nodes/input.hpp"

namespace Nodes {
    Input::Input(const GumboElement *el)
        : Element(el)
    {

    }

    void Input::printw(WINDOW *window) const
    {
        wprintw(window, "________________\n");
    }
}
