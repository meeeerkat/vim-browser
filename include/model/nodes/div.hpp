#ifndef __MODEL_NODES_DIV_H__
#define __MODEL_NODES_DIV_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Div : public Element {
        public:
            Div(const GumboElement *el);
            virtual void printw(WINDOW *window) const;
    };
}

#endif
