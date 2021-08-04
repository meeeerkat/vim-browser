#include "model/nodes/br.hpp"


namespace Nodes {
    Br::Br(const GumboElement *el, BuildData &build_data)
        : Element(build_data)
    {
        (void) el;

    }

    void Br::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        wprintw(window, "\n");
    }
}
