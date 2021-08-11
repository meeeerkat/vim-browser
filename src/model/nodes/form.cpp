#include "model/nodes/form.hpp"
#include "model/nodes/input.hpp"
#include "model/nodes/loader.hpp"
#include "helpers/url.hpp"
#include "commands/open.hpp"
#include <iostream>


namespace Nodes {

    Form::Form(const GumboElement *el, BuildData &build_data)
        : Element(build_data)
    {
        // Forms aren't supposed to be nested so build_data.current_form is supposed to be nullptr here
        build_data.current_form = this;
        Element::setup_children(el, build_data);
        build_data.current_form = nullptr;

        base_url = build_data.base_url;

        action = load_attribute(el, "action");
        Helpers::Url::fix(action, base_url);
        
        std::string method_str = load_attribute(el, "method");
        method = Helpers::HttpRequest::GET;
        if (method_str == "post")
            method = Helpers::HttpRequest::POST;
    }

    void Form::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Element::printw(window, printing_options);
        Element::print_children(window, printing_options);
    }
    
    void Form::add_input(Input *input)
    {
        inputs.push_back(input);
    }

    void Form::send()
    {
        Helpers::HttpRequest request{action, method};
        for (Input* input : inputs)
            if (!input->get_name().empty())
                request.fields += input->get_name() + "=" + input->get_value() + "&";

        std::cerr << request.fields << "\n";
        Commands::open_in_current_tab(request);
    }

}
