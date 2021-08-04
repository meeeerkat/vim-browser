#include "model/nodes/select.hpp"
#include "model/nodes/loader.hpp"


namespace Nodes {
    Select::Select(const GumboElement *el, BuildData &build_data)
        : Element(build_data)
    {
        // Setting up options
        const GumboVector* gchildren = &el->children;
        for (uint16_t i=0; i < gchildren->length; i++) {
            GumboNode *gchild = static_cast<GumboNode*>(gchildren->data[i]);
            if (gchild->type == GUMBO_NODE_ELEMENT) {
                GumboElement *child_el = &gchild->v.element;
                std::string value = load_attribute(child_el, "value");
                GumboNode* text_node = static_cast<GumboNode*>(child_el->children.data[0]);
                if (text_node->type == GUMBO_NODE_TEXT) {
                    options.push_back(value);
                    option_labels[value] = text_node->v.text.text;
                }
            }
        }
        if (options.size() > 0)
            value = options[0];
        else
            value = "";
    }

    void Select::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Element::printw(window, printing_options);
        if (is_value_set()) {
            const std::string label = option_labels.at(value);
            wprintw(window, "%s ", label.c_str());
        }
    }

    bool Select::is_value_set() const
    {
        return option_labels.count(value);
    }
}
