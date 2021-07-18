#ifndef __MODEL_NODES_NODE_H__
#define __MODEL_NODES_NODE_H__

#include <gumbo.h>
#include <ncurses.h>
#include <vector>


namespace Nodes {
    
    class Element;
    struct BuildData {
        std::vector<Element*> interactive_elements;
    };
    struct PrintingOptions {
        bool show_interactions;
    };

    class Node {
        public:
            Node(BuildData *build_data);
            virtual ~Node();
            virtual void printw(WINDOW *window, PrintingOptions *printing_options) const = 0;
    };
}

#endif
