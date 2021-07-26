#ifndef __MODEL_NODES_NODE_H__
#define __MODEL_NODES_NODE_H__

#include <gumbo.h>
#include <ncurses.h>
#include <vector>
#include <string>


namespace Nodes {
    
    class InteractiveElement;

    struct BuildData {
        std::vector<InteractiveElement*> interactive_elements;
        std::string base_url;
    };
    struct PrintingOptions {
        enum InteractionType { None, Link, LinkNewTab, Content, Input };
        InteractionType interaction_type = InteractionType::None;
        std::string interaction_current_id;
    };

    class Node {
        public:
            Node(BuildData &build_data);
            virtual ~Node();
            virtual void printw(WINDOW *window, PrintingOptions &printing_options) const = 0;
    };
}

#endif
