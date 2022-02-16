#ifndef __MODEL_NODES_TD_HPP__
#define __MODEL_NODES_TD_HPP__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Td : public Element {
        public:
            Td(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
    };
}

#endif
