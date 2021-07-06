#ifndef __MODEL_ELEMENTS_LOADER_H__
#define __MODEL_ELEMENTS_LOADER_H__

#include <string>
#include <gumbo.h>
#include "model/nodes/element.hpp"

namespace Nodes {
    // Finds the right constructor to call & builds the right Element
    void load(std::vector<Node*> *nodes, const GumboNode *node);

    std::string load_attribute(const GumboElement *el, const std::string name);
}

#endif
