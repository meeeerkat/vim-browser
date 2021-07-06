#include <map>
#include "model/nodes/loader.hpp"
#include "model/nodes/body.hpp"
#include "model/nodes/a.hpp"
#include "model/nodes/p.hpp"
#include "model/nodes/input.hpp"
#include "model/nodes/img.hpp"
#include "model/nodes/h1.hpp"
#include "model/nodes/h2.hpp"
#include "model/nodes/h3.hpp"
#include "model/nodes/h4.hpp"
#include "model/nodes/h5.hpp"
#include "model/nodes/h6.hpp"
#include "model/nodes/ul.hpp"
#include "model/nodes/ol.hpp"
#include "model/nodes/li.hpp"
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
            { GUMBO_TAG_A, create<A> },
            { GUMBO_TAG_P, create<P> },
            { GUMBO_TAG_INPUT, create<Input> },
            { GUMBO_TAG_IMG, create<Img> },
            { GUMBO_TAG_H1, create<H1> },
            { GUMBO_TAG_H2, create<H2> },
            { GUMBO_TAG_H3, create<H3> },
            { GUMBO_TAG_H4, create<H4> },
            { GUMBO_TAG_H5, create<H5> },
            { GUMBO_TAG_H6, create<H6> },
            { GUMBO_TAG_UL, create<Ul> },
            { GUMBO_TAG_OL, create<Ol> },
            { GUMBO_TAG_LI, create<Li> },
        };

        std::map<int, bool> stop_elements {
            { GUMBO_TAG_SCRIPT, true },
        };
    }

    void load(std::vector<Node*> *nodes, const GumboNode *gnode)
    {
        if(gnode->type == GUMBO_NODE_TEXT) {
            nodes->push_back(new Text(&gnode->v.text));
            return;
        }

        if (gnode->type == GUMBO_NODE_ELEMENT) {
            const GumboElement *el = &gnode->v.element;
            if (stop_elements.count(el->tag) > 0)
                return;
            if (elements_creators.count(el->tag) == 0) {
                // Jumping this element and directly loading it's children
                const GumboVector* gumbo_children = &el->children;
                for (uint16_t i=0; i < gumbo_children->length; i++) {
                    GumboNode *child = static_cast<GumboNode*>(gumbo_children->data[i]);
                    load(nodes, child);
                }
                return;
            }
            nodes->push_back(elements_creators[el->tag](el));
            return;
        }

    }

    std::string load_attribute(const GumboElement *el, const std::string name)
    {
        GumboAttribute *attr = gumbo_get_attribute(&el->attributes, name.c_str());
        if (attr)
            return std::string(attr->value);
        return "";
    }
}