#ifndef __MODEL_NODES_NODE_H__
#define __MODEL_NODES_NODE_H__

#include <gumbo.h>
#include <ncurses.h>
#include <vector>
#include <string>


namespace Nodes {
    
    class InteractiveElement;
    class Form;

    struct BuildData {
        std::vector<InteractiveElement*> interactive_elements;
        std::string base_url;
        Form *current_form;
    };

    struct PrintingOptions {
        enum InteractionType { CurrentTab, NewTab, None };
        InteractionType interaction_type = InteractionType::None;
        std::string interaction_current_id;
        int cursor_y=-1, cursor_x=-1;
    };

    class Node {
        public:
            Node(BuildData &build_data);
            virtual ~Node();
            virtual void printw(WINDOW *window, PrintingOptions &printing_options) = 0;
    };
}

#endif
