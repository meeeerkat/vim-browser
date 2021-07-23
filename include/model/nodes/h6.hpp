#ifndef __MODEL_NODES_H6_H__
#define __MODEL_NODES_H6_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class H6 : public Element {
        public:
            H6(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options) const;
    };
}

#endif
