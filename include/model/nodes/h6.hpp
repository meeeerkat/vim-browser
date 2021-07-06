#ifndef __MODEL_NODES_H6_H__
#define __MODEL_NODES_H6_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class H6 : public Element {
        public:
            H6(const GumboElement *el);
            virtual void printw(WINDOW *window) const;
    };
}

#endif
