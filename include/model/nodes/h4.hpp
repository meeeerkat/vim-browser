#ifndef __MODEL_NODES_H4_H__
#define __MODEL_NODES_H4_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class H4 : public Element {
        public:
            H4(const GumboElement *el);
            virtual void printw(WINDOW *window) const;
    };
}

#endif
