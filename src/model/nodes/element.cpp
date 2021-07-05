#include "model/nodes/element.hpp"
#include "model/nodes/loader.hpp"


namespace Nodes {
    Element::Element(const GumboElement* el)
    {
        // Setting up children
        const GumboVector* gumbo_children = &el->children;
        for (uint16_t i=0; i < gumbo_children->length; i++) {
            GumboNode *child = static_cast<GumboNode*>(gumbo_children->data[i]);
            Node *child_node = Nodes::load(child);
            if (child_node)
                children.push_back(child_node);
        }
    }

    Element::~Element()
    {
        for (auto child : children)
            delete child;
    }
    
    void Element::printw(WINDOW *window) const
    {
        for (Node *child : children)
            child->printw(window);
    }
}
