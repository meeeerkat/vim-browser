#ifndef __MODEL_NODES_IMG_H__
#define __MODEL_NODES_IMG_H__

#include <string>
#include "model/nodes/interactive_element.hpp"

namespace Nodes {
    class Img : public InteractiveElement {
        public:
            Img(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
            
            virtual void interact(PrintingOptions::InteractionType type);

        protected:
            std::string alt;
            std::string src;
    };
}

#endif
