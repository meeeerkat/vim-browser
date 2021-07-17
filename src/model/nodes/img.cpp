#include "model/nodes/img.hpp"
#include "model/nodes/loader.hpp"

namespace Nodes {
    Img::Img(const GumboElement *el)
        : Element(el)
    {
        alt = load_attribute(el, "alt");
        src = load_attribute(el, "src");
    }

    void Img::printw(WINDOW *window) const
    {
        if (alt.empty())
            wprintw(window, "*%s* ", src.c_str());
        else
            wprintw(window, "*%s* ", alt.c_str());
    }
}
