#ifndef __MODEL_NODES_FORM_HPP__
#define __MODEL_NODES_FORM_HPP__

#include "model/nodes/element.hpp"
#include <string>
#include <vector>
#include "helpers/http_request.hpp"

class App;

namespace Nodes {
    class Input;

    class Form : public Element {
        public:
            Form(const GumboElement *el, BuildData &build_data);
            virtual void printw(WINDOW *window, PrintingOptions &printing_options);

            void add_input(Input *input);
            void send(App *app, bool in_new_tab = false) const;

        private:
            std::vector<Input*> inputs;
            std::string base_url;

            std::string action;
            Helpers::HttpRequest::Type method;
    };

}

#endif
