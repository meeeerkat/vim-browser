#ifndef __MODEL_NODES_DIV_H__
#define __MODEL_NODES_DIV_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Div : public Element {
        public:
            Div(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options) const;
    };
}

#endif
