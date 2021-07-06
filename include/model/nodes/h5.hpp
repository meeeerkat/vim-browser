#ifndef __MODEL_NODES_H5_H__
#define __MODEL_NODES_H5_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class H5 : public Element {
        public:
            H5(const GumboElement *el);
            virtual void printw(WINDOW *window) const;
    };
}

#endif
