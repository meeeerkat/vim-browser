#include "model/nodes/br.hpp"


namespace Nodes {
    Br::Br(const GumboElement *el)
        : Element()
    {
        (void) el;

    }

    void Br::printw(WINDOW *window) const
    {
        wprintw(window, "\n");
    }
}
