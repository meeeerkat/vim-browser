#ifndef __MODEL_NODES_SELECT_H__
#define __MODEL_NODES_SELECT_H__

#include <map>
#include <vector>
#include <string>
#include "model/nodes/element.hpp"

namespace Nodes {
    class Select : public Element {
        public:
            Select(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options) const;

        protected:
            bool is_value_set() const;
            std::map<std::string, std::string> option_labels;
            std::vector<std::string> options;
            std::string value;
    };
}

#endif
