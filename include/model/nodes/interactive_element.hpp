#ifndef __MODEL_NODES_INTERACTIVEELEMENT_H__
#define __MODEL_NODES_INTERACTIVEELEMENT_H__

#include "model/nodes/element.hpp"
#include <stdint.h>

namespace Nodes {
    class InteractiveElement : public Element {
        public:
            InteractiveElement(const GumboElement *el, BuildData &build_data);
            virtual ~InteractiveElement();
            virtual void printw(WINDOW *window, PrintingOptions &printing_options) const;

            virtual void interact(PrintingOptions::InteractionType type) = 0;

        protected:
            uint32_t id;
    };
}

#endif
