#ifndef __MODEL_NODES_BODY_H__
#define __MODEL_NODES_BODY_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Body : public Element {
        public:
            Body(const GumboElement *el, BuildData &build_data);
            Body(BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
    };
}

#endif
