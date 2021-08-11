#include "model/nodes/text_input.hpp"
#include "controller.hpp"
#include "input_handler.hpp"
#include "widgets/page.hpp"


namespace Nodes {

    TextInput::TextInput(const GumboElement *el, BuildData &build_data)
        : Input(el, build_data)
    {
        model.set_value(value);
    }

    void TextInput::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        Input::printw(window, printing_options);

        wprintw(window, "%s________________ ", value.c_str());

        Input::print_id(window, printing_options);
    }
    
    void TextInput::interact(PrintingOptions::InteractionType)
    {
        refresh_display();
        while (true) {
            uint16_t code = Controller::input_handler->get_input();
            if (!model.handle_input(code))
                return;
            value = std::string(model.get_value());
            refresh_display();
        }
    }

    void TextInput::refresh_display() const
    {
        PrintingOptions printing_options;
        printing_options.cursor_y = y;
        printing_options.cursor_x = x + model.get_cursor();
        Controller::page_widget->refresh_display(printing_options);
    }

}
