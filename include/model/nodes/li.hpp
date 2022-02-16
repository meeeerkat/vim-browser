#ifndef __MODEL_NODES_LI_HPP__
#define __MODEL_NODES_LI_HPP__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Li : public Element {
        public:
            Li(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
    };
}

#endif
