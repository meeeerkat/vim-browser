#ifndef __MODEL_NODES_INPUT_H__
#define __MODEL_NODES_INPUT_H__

#include <string>
#include "model/nodes/element.hpp"

namespace Nodes {
    class Input : public Element {
        public:
            Input(const GumboElement *el);
            virtual void printw(WINDOW *window) const;

        protected:
            std::string type;
            std::string value;
    };
}

#endif
