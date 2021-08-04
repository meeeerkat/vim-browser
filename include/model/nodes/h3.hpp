#ifndef __MODEL_NODES_H3_H__
#define __MODEL_NODES_H3_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class H3 : public Element {
        public:
            H3(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
    };
}

#endif
