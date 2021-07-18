#ifndef __MODEL_NODES_OL_H__
#define __MODEL_NODES_OL_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Ol : public Element {
        public:
            Ol(const GumboElement *el, BuildData *build_data);
            virtual void printw(WINDOW *window, PrintingOptions *printing_options) const;
    };
}

#endif
