#ifndef __MODEL_NODES_TEXTINPUT_H__
#define __MODEL_NODES_TEXTINPUT_H__

#include "model/nodes/input.hpp"
#include "model/text_input.hpp"

namespace Nodes {
    class TextInput : public Input {
        public:
            TextInput(const GumboElement *el, BuildData &build_data);

            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
            virtual void interact(PrintingOptions::InteractionType type);

        private:
            Model::TextInput model;
            
            void refresh_display() const;
    };
}

#endif