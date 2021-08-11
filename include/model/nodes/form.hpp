#ifndef __MODEL_NODES_FORM_H__
#define __MODEL_NODES_FORM_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Form : public Element {
        public:
            Form(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);

            void send();
    };
}

#endif
