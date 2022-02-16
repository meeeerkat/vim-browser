#ifndef __MODEL_NODES_TEXTINPUT_HPP__
#define __MODEL_NODES_TEXTINPUT_HPP__

#include "model/nodes/input.hpp"
#include "vim/model/text_input.hpp"

namespace Nodes {
    class TextInput : public Input {
        public:
            TextInput(const GumboElement *el, BuildData &build_data);

            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
            virtual void interact(App *app, PrintingOptions::InteractionType type);

        private:
            Vim::Model::TextInput model;
            
            void refresh_display(App *app) const;
    };
}

#endif
