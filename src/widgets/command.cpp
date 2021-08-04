#include "widgets/command.hpp"


namespace Widgets {

Command::Command(int (*exec_command_callback_p) (const std::string&))
    : Widget()
{
    exec_command_callback = exec_command_callback_p;

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

void Command::handle_input(const std::string *base_command)
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
            if (history_cursor > 0) {
                command.set_value(history[--history_cursor]);
            }
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
        else if (!command.handle_input(code)) {
            if (command.get_value().empty()) {
                clear();
                reset();
                return;
            }
            history.push_back(std::string(command.get_value()));
            clear();
            exec_command_callback(command.get_value());
            reset();
            return;
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
