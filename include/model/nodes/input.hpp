#ifndef __MODEL_NODES_INPUT_H__
#define __MODEL_NODES_INPUT_H__

#include <string>
#include "model/nodes/interactive_element.hpp"

namespace Nodes {
    class Input : public InteractiveElement {
        public:
            Input(const GumboElement *el, BuildData &build_data, bool is_interactive = true);

            virtual void interact(App *app, PrintingOptions::InteractionType type) = 0;

            std::string get_name() const;
            std::string get_value() const;

        protected:
            std::string name;
            std::string value;
    };
}

#endif
