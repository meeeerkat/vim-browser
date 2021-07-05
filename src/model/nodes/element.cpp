#include "model/nodes/element.hpp"
#include "model/nodes/loader.hpp"


namespace Nodes {
    Element::Element(const GumboElement* el)
    {
        // Setting up children
        const GumboVector* gumbo_children = &el->children;
        children.resize(gumbo_children->length);
        for (uint16_t i=0; i < gumbo_children->length; i++) {
            GumboNode *child = static_cast<GumboNode*>(gumbo_children->data[i]);
            children[i] = Nodes::load(child);
        }
    }

    Element::~Element()
    {
        for (auto child : children)
            delete child;
    }
}
