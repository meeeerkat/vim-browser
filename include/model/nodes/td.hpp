#ifndef __MODEL_NODES_TD_H__
#define __MODEL_NODES_TD_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Td : public Element {
        public:
            Td(const GumboElement *el);
            virtual void printw(WINDOW *window) const;
    };
}

#endif
