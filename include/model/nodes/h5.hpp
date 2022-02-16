#ifndef __MODEL_NODES_H5_HPP__
#define __MODEL_NODES_H5_HPP__

#include "model/nodes/element.hpp"

namespace Nodes {
    class H5 : public Element {
        public:
            H5(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);
    };
}

#endif
