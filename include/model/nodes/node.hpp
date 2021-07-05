#ifndef __MODEL_NODES_NODE_H__
#define __MODEL_NODES_NODE_H__

#include <gumbo.h>
#include <ncurses.h>

namespace Nodes {
    class Node {
        public:
            Node();
            virtual ~Node();
            virtual void printw(WINDOW *window, uint16_t *lines_nb) = 0;
    };
}

#endif
