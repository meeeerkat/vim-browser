#include "model/nodes/loader.hpp"
#include "model/nodes/input.hpp"
#include "controller.hpp"
#include "input_handler.hpp"
#include "widgets/page.hpp"


namespace Nodes {
    Input::Input(const GumboElement *el, BuildData &build_data)
        : InteractiveElement(el, build_data)
    {
        type = Nodes::load_attribute(el, "type");
        value = Nodes::load_attribute(el, "value");
    }

    void Input::printw(WINDOW *window, PrintingOptions &printing_options) const
    {
        if (type == "text")
            wprintw(window, "%s________________ ", value.c_str());
        else if (type == "submit") {
            wattron(window, A_BOLD);
            wprintw(window, "%s", value.c_str());
            wattroff(window, A_BOLD);
        }
        
        if (printing_options.interaction_type == PrintingOptions::InteractionType::Input)
            InteractiveElement::printw(window, printing_options);
    }
    
    void Input::interact(PrintingOptions::InteractionType interaction_type)
    {
        if (interaction_type != PrintingOptions::InteractionType::Input)
            return;

        if (type == "text") {
            while (true) {
                char input = Controller::input_handler->get_input();
                if (input == '\n')
                    return;
                value += input;
                Controller::page_widget->refresh_display(Nodes::PrintingOptions{});
            }
        }
        else if (type == "select") {
        }
    }
}
