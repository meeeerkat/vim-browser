#ifndef __MODEL_NODES_A_H__
#define __MODEL_NODES_A_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class A : public Element {
        public:
            A(const GumboElement *el);
            virtual void printw(WINDOW *window) const;
    };
}

#endif
