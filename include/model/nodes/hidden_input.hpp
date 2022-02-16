#ifndef __MODEL_NODES_HIDDENINPUT_HPP__
#define __MODEL_NODES_HIDDENINPUT_HPP__

#include "model/nodes/input.hpp"

namespace Nodes {
    class HiddenInput : public Input {
        public:
            HiddenInput(const GumboElement *el, BuildData &build_data);
            
            virtual void interact(App *app, PrintingOptions::InteractionType type);
    };
}

#endif
