#include "widgets/command.hpp"
#include "app.hpp"


namespace Widgets {

Command::Command()
    : Widget()
{
    // Takes only the last line
    window = newwin(1, COLS, LINES-1, 0);
    keypad(window, TRUE);

    reset();
}
Command::~Command()
{
    delwin(window);
}


// Inputs
void Command::reset()
{
    command.reset();
    history_cursor = history.size();
}
void Command::clear() const
{
    if (!can_refresh())
        return;

    wclear(window);
    wrefresh(window);
}

void Command::refresh_display() const
{
    wclear(window);
    // noecho mode so need to reprint the character where it's needed
    mvwprintw(window, 0, 0, ":%s", command.get_value().c_str());
    wmove(window, 0, command.get_cursor()+1);

    wrefresh(window);
}

void Command::handle_input(App *app, const std::string *base_command)
{
    wclear(window); // Necessary to clear messages
    if (base_command) {
        command.set_value(std::string(*base_command));
        refresh_display();
    }
    else
        waddch(window, ':');
    wrefresh(window);
    
    while (TRUE) {
        const uint16_t code = wgetch(window);
        if (code == KEY_UP) {
            if (history_cursor > 0)
                command.set_value(history[--history_cursor]);
        }
        else if (code == KEY_DOWN) {
            if (history_cursor < history.size()) {
                history_cursor++;
                if (history_cursor < history.size())
                    command.set_value(history[history_cursor]);
                else
                    command.set_value("");
            }
        }
        else {
            Model::TextInput::InputState input_state = command.handle_input(code);
            switch (input_state) {
                case Model::TextInput::InputState::WaitingInput:
                    break;

                case Model::TextInput::InputState::Canceled:
                    clear();
                    reset();
                    return;

                case Model::TextInput::InputState::Sent:
                    // Checking first if the command isn't empty to avoid pushing an empty string to the commands' history
                    if (command.get_value().empty()) {
                        clear();
                        reset();
                        return;
                    }
                    // Executing command & pushing it in the commands' history
                    history.push_back(std::string(command.get_value()));
                    clear();
                    app->exec(command.get_value());
                    reset();
                    return;
                    break;
            }
        }
        refresh_display();
    }
}


void Command::print_message(const std::string &message) const
{
    if (!can_refresh())
        return;

    wclear(window);
    wprintw(window, "%s", message.c_str());
    wrefresh(window);
}

}
