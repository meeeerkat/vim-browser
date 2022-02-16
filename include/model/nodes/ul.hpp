#ifndef __MODEL_NODES_UL_HPP__
#define __MODEL_NODES_UL_HPP__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Ul : public Element {
        public:
            Ul(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
    };
}

#endif
