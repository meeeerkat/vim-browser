#ifndef __MODEL_NODES_INPUT_H__
#define __MODEL_NODES_INPUT_H__

#include <string>
#include "model/nodes/interactive_element.hpp"
#include "model/text_input.hpp"

namespace Nodes {
    class Input : public InteractiveElement {
        public:
            Input(const GumboElement *el, BuildData &build_data);
            virtual ~Input();

            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
            
            virtual void interact(PrintingOptions::InteractionType type);

        protected:
            std::string type;
            std::string value;

            TextInput *text_input = nullptr;

            void refresh_display() const;
    };
}

#endif
