#include "model/nodes/submit_input.hpp"
#include "model/nodes/form.hpp"


namespace Nodes {

    SubmitInput::SubmitInput(const GumboElement *el, BuildData &build_data)
        : Input(el, build_data)
    {
        form = build_data.current_form;
    }

    void SubmitInput::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Input::printw(window, printing_options);

        wattron(window, A_BOLD);
        wprintw(window, "%s ", value.c_str());
        wattroff(window, A_BOLD);

        Input::print_id(window, printing_options);
    }
    
    void SubmitInput::interact(PrintingOptions::InteractionType interaction_type)
    {
        form->send(interaction_type == PrintingOptions::InteractionType::NewTab);
    }

}
