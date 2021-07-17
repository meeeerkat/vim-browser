#include "model/nodes/loader.hpp"
#include "model/nodes/input.hpp"


namespace Nodes {
    Input::Input(const GumboElement *el)
        : Element(el)
    {
        type = Nodes::load_attribute(el, "type");
        value = Nodes::load_attribute(el, "value");
    }

    void Input::printw(WINDOW *window) const
    {
        if (type == "text")
            wprintw(window, "%s________________ ", value.c_str());
        else if (type == "submit") {
            wattron(window, A_BOLD);
            wprintw(window, "%s", value.c_str());
            wattroff(window, A_BOLD);
        }
    }
}
