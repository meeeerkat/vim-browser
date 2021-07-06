#ifndef __MODEL_NODES_UL_H__
#define __MODEL_NODES_UL_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Ul : public Element {
        public:
            Ul(const GumboElement *el);
            virtual void printw(WINDOW *window) const;
    };
}

#endif
