#ifndef __MODEL_NODES_INPUT_H__
#define __MODEL_NODES_INPUT_H__

#include <string>
#include "model/nodes/interactive_element.hpp"

namespace Nodes {
    class Input : public InteractiveElement {
        public:
            Input(const GumboElement *el, BuildData &build_data);

            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
            virtual void interact(PrintingOptions::InteractionType type) = 0;
            void print_id(WINDOW *window, PrintingOptions &printing_options) const;
            std::string get_name() const;
            std::string get_value() const;

        protected:
            std::string name;
            std::string value;
    };
}

#endif
