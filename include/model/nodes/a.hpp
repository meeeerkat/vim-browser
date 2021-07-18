#ifndef __MODEL_NODES_A_H__
#define __MODEL_NODES_A_H__

#include "model/nodes/interactive_element.hpp"

namespace Nodes {
    class A : public InteractiveElement {
        public:
            A(const GumboElement *el, BuildData *build_data);
            virtual void printw(WINDOW *window, PrintingOptions *printing_options) const;
    };
}

#endif
