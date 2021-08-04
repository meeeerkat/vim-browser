#include "model/nodes/element.hpp"
#include "model/nodes/loader.hpp"
#include <ncurses.h>


namespace Nodes {
    Element::Element(BuildData &build_data)
        : Node(build_data)
    {

    }

    Element::Element(const GumboElement* el, BuildData &build_data)
        : Element(build_data)
    {
        // Setting up children
        const GumboVector* gchildren = &el->children;
        for (uint16_t i=0; i < gchildren->length; i++) {
            GumboNode *gchild = static_cast<GumboNode*>(gchildren->data[i]);
            Nodes::load(&children, gchild, build_data);
        }
    }
   
    Element::~Element()
    {
        for (Node *child : children)
            delete child;
    }
    
    void Element::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        getyx(window, y, x);
    }

    void Element::print_children(WINDOW *window, PrintingOptions &printing_options) const
    {
        for (Node *child : children)
            child->printw(window, printing_options);
    }

}
