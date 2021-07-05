#include <map>
#include "model/nodes/loader.hpp"
#include "model/nodes/body.hpp"
#include "model/nodes/text.hpp"


namespace Nodes {

    template <typename T>
    inline Node* create(const GumboElement *el)
    {
        return new T(el);
    }

    namespace {
        std::map<int, Node* (*) (const GumboElement*)> elements_creators = {
            { GUMBO_TAG_BODY, create<Body> },
        };
    }

    Node *load(const GumboNode *node)
    {
        if (node->type == GUMBO_NODE_ELEMENT) {
            if (node->v.element.tag == GUMBO_TAG_SCRIPT)
                return NULL;
            if (elements_creators.count(node->v.element.tag) == 0)
                return new Element(&node->v.element);
            return elements_creators[node->v.element.tag](&node->v.element);
        }
        else if(node->type == GUMBO_NODE_TEXT)
            return new Text(&node->v.text);
        return NULL;
    }

    std::string load_attribute(const GumboElement *el, const std::string name)
    {
        GumboAttribute *attr = gumbo_get_attribute(&el->attributes, name.c_str());
        if (attr)
            return std::string(attr->value);
        return "";
    }
}
