#ifndef __MODEL_NODES_BODY_H__
#define __MODEL_NODES_BODY_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Body : public Element {
        public:
            Body(const GumboElement *el);
    };
}

#endif
