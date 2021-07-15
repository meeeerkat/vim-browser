#ifndef __MODEL_NODES_FORM_H__
#define __MODEL_NODES_FORM_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Form : public Element {
        public:
            Form(const GumboElement *el);
            virtual void printw(WINDOW *window) const;
    };
}

#endif
