#ifndef __MODEL_NODES_TR_H__
#define __MODEL_NODES_TR_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Tr : public Element {
        public:
            Tr(const GumboElement *el);
            virtual void printw(WINDOW *window) const;
    };
}

#endif
