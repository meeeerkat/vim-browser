#ifndef __MODEL_NODES_HIDDENINPUT_H__
#define __MODEL_NODES_HIDDENINPUT_H__

#include "model/nodes/input.hpp"

namespace Nodes {
    class HiddenInput : public Input {
        public:
            HiddenInput(const GumboElement *el, BuildData &build_data);
            
            virtual void interact(PrintingOptions::InteractionType type);
    };
}

#endif
