#ifndef __MODEL_NODES_LI_H__
#define __MODEL_NODES_LI_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Li : public Element {
        public:
            Li(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options) const;
    };
}

#endif
