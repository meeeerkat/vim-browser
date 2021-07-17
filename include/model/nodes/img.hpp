#ifndef __MODEL_NODES_IMG_H__
#define __MODEL_NODES_IMG_H__

#include <string>
#include "model/nodes/element.hpp"

namespace Nodes {
    class Img : public Element {
        public:
            Img(const GumboElement *el);
            virtual void printw(WINDOW *window) const;

        protected:
            std::string alt;
            //std::string src;
    };
}

#endif
