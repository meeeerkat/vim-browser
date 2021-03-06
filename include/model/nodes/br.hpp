#ifndef __MODEL_NODES_BR_HPP__
#define __MODEL_NODES_BR_HPP__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Br : public Element {
        public:
            Br(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
    };
}

#endif
