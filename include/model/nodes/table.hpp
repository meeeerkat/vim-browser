#ifndef __MODEL_NODES_TABLE_H__
#define __MODEL_NODES_TABLE_H__

#include "model/nodes/element.hpp"

namespace Nodes {
    class Table : public Element {
        public:
            Table(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
    };
}

#endif
