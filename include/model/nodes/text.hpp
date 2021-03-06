#ifndef __MODEL_NODES_TEXT_HPP__
#define __MODEL_NODES_TEXT_HPP__

#include <string>
#include "model/nodes/node.hpp"

namespace Nodes {
    class Text : public Node {
        public:
            Text(const GumboText *text, BuildData &build_data);
            Text(const std::string &text, BuildData &build_data);
            ~Text();
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);

        protected:
            std::string text;
    };
}

#endif
