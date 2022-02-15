#ifndef __MODEL_NODES_SUBMITINPUT_H__
#define __MODEL_NODES_SUBMITINPUT_H__

#include "model/nodes/input.hpp"

namespace Nodes {

    class Form;

    class SubmitInput : public Input {
        public:
            SubmitInput(const GumboElement *el, BuildData &build_data);

            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
            virtual void interact(App *app, PrintingOptions::InteractionType type);

        private:
            Form *form;
    };
}

#endif
