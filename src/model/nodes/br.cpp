#include "model/nodes/br.hpp"


namespace Nodes {
    Br::Br(const GumboElement *, BuildData &build_data)
        : Element(build_data)
    {

    }

    void Br::printw(WINDOW *window, PrintingOptions &)
    {
        wprintw(window, "\n");
    }
}
