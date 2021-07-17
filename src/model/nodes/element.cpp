#include "model/nodes/element.hpp"
#include "model/nodes/loader.hpp"


namespace Nodes {
    Element::Element()
    {

    }

    Element::Element(const GumboElement* el)
    {
        // Setting up children
        const GumboVector* gchildren = &el->children;
        for (uint16_t i=0; i < gchildren->length; i++) {
            GumboNode *gchild = static_cast<GumboNode*>(gchildren->data[i]);
            Nodes::load(&children, gchild);
        }
    }
   
    Element::~Element()
    {
        for (Node *child : children)
            delete child;
    }
    
    void Element::printw(WINDOW *window) const
    {
        for (Node *child : children)
            child->printw(window);
    }
}
