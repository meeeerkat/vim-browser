#ifndef __MODEL_NODES_TEXT_H__
#define __MODEL_NODES_TEXT_H__

#include <string>
#include "model/nodes/node.hpp"

namespace Nodes {
    class Text : public Node {
        public:
            Text(const GumboText *text);
            ~Text();
            virtual void printw(WINDOW *window) const;

        protected:
            std::string text;
    };
}

#endif
