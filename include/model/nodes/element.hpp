#ifndef __MODEL_NODES_ELEMENT_H__
#define __MODEL_NODES_ELEMENT_H__

#include <vector>
#include <gumbo.h>
#include "model/nodes/node.hpp"

namespace Nodes {
    class Element : public Node {
        public:
            Element(BuildData &build_data);
            Element(const GumboElement *el, BuildData &build_data);
            virtual ~Element();
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
            virtual void print_children(WINDOW *window, PrintingOptions &printing_options) const;

        protected:
            std::vector<Node*> children;
            int y,x;
    };
}

#endif
