#ifndef __MODEL_NODES_H1_H__
#define __MODEL_NODES_H1_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class H1 : public Element {
        public:
            H1(const GumboElement *el);
            virtual void printw(WINDOW *window) const;
    };
}

#endif
