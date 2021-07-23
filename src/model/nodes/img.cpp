#include "model/nodes/img.hpp"
#include "model/nodes/loader.hpp"

namespace Nodes {
    Img::Img(const GumboElement *el, BuildData &build_data)
        : Element(el, build_data)
    {
        alt = load_attribute(el, "alt");
        src = load_attribute(el, "src");
    }

    void Img::printw(WINDOW *window, PrintingOptions &printing_options) const
    {
        if (alt.empty())
            wprintw(window, "*%s* ", src.c_str());
        else
            wprintw(window, "*%s* ", alt.c_str());
    }
}
