#ifndef __MODEL_NODES_H4_HPP__
#define __MODEL_NODES_H4_HPP__

#include "model/nodes/element.hpp"

namespace Nodes {
    class H4 : public Element {
        public:
            H4(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
    };
}

#endif
