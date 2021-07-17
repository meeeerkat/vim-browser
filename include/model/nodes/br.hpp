#ifndef __MODEL_NODES_BR_H__
#define __MODEL_NODES_BR_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Br : public Element {
        public:
            Br(const GumboElement *el);
            virtual void printw(WINDOW *window) const;
    };
}

#endif
