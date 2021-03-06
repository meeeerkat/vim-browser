#ifndef __MODEL_NODES_A_HPP__
#define __MODEL_NODES_A_HPP__

#include <string>
#include "model/nodes/interactive_element.hpp"

namespace Nodes {
    class A : public InteractiveElement {
        public:
            A(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
            
            virtual void interact(App *app, PrintingOptions::InteractionType type);

        protected:
            std::string base_url;
            std::string href;
    };
}

#endif
