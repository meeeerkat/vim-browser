#ifndef __MODEL_NODES_H2_H__
#define __MODEL_NODES_H2_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class H2 : public Element {
        public:
            H2(const GumboElement *el);
            virtual void printw(WINDOW *window) const;
    };
}

#endif
