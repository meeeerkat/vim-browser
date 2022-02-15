#include "model/nodes/text_input.hpp"
#include "input_handler.hpp"
#include "widgets/page.hpp"
#include "app.hpp"


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
    
    void TextInput::interact(App *app, PrintingOptions::InteractionType)
    {
        refresh_display(app);
        while (true) {
            uint16_t code = app->getInputHandler()->get_input();
            switch (model.handle_input(code)) {
                case Model::TextInput::InputState::WaitingInput:
                    value = std::string(model.get_value());
                    refresh_display(app);
                    break;

                case Model::TextInput::InputState::Canceled:
                case Model::TextInput::InputState::Sent:
                    return;
            }
        }
    }

    void TextInput::refresh_display(App *app) const
    {
        PrintingOptions printing_options;
        printing_options.cursor_y = y;
        printing_options.cursor_x = x + model.get_cursor();
        app->getPageWidget()->refresh_display(printing_options);
    }

}
