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
            void setup_children(const GumboElement* el, BuildData &build_data);
            virtual ~Element();

            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
            virtual void print_children(WINDOW *window, PrintingOptions &printing_options) const;

            // Public because you can't mess up the invariant
            // no matter what you do with this vector
            std::vector<Node*> children;

        protected:
            int y,x;
    };
}

#endif
