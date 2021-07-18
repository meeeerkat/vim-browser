#ifndef __MODEL_NODES_INPUT_H__
#define __MODEL_NODES_INPUT_H__

#include <string>
#include "model/nodes/interactive_element.hpp"

namespace Nodes {
    class Input : public InteractiveElement {
        public:
            Input(const GumboElement *el, BuildData *build_data);
            virtual void printw(WINDOW *window, PrintingOptions *printing_options) const;

        protected:
            std::string type;
            std::string value;
    };
}

#endif
