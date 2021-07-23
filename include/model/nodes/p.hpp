#ifndef __MODEL_NODES_P_H__
#define __MODEL_NODES_P_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class P : public Element {
        public:
            P(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options) const;
    };
}

#endif
