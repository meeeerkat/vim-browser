#ifndef __MODEL_NODES_ELEMENT_H__
#define __MODEL_NODES_ELEMENT_H__

#include <vector>
#include <gumbo.h>
#include "model/nodes/node.hpp"

namespace Nodes {
    class Element : public Node {
        public:
            Element(const GumboElement *element);
            virtual ~Element();
            virtual void printw(WINDOW *window) const;

        protected:
            std::vector<Node*> children;
    };
}

#endif
