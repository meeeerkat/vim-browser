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
    command_cursor = 0;
    current_command = "";
    history_cursor = history.size();
}
void Command::clear() const
{
    if (!can_refresh())
        return;

    wclear(window);
    wrefresh(window);
}

void Command::print_current_command() const
{
    wclear(window);
    // noecho mode so need to reprint the character where it's needed
    mvwprintw(window, 0, 0, ":%s", current_command.c_str());
    wmove(window, 0, command_cursor+1);

    wrefresh(window);
}

void Command::insert_char(char c)
{
    current_command.insert(command_cursor, 1, c);
    command_cursor++;
}

void Command::delete_char()
{
    if (command_cursor < current_command.length())
        current_command.erase(command_cursor, 1);
    else if (command_cursor == current_command.length() && current_command.length() > 0) {
        current_command.erase(command_cursor-1, 1);
        command_cursor--;
    }
}

void Command::set_command(const std::string &command)
{
    current_command = command;
    command_cursor = command.length();
}


void Command::handle_input(const std::string *base_command)
{
    wclear(window); // Necessary to clear messages
    if (base_command) {
        set_command(std::string(*base_command));
        print_current_command();
    }
    else
        waddch(window, ':');
    wrefresh(window);
    
    while (TRUE) {
        const uint16_t code = wgetch(window);
        // TODO: handle ESC to leave command input forwarding
        // (or another key since ncurses seems to have problems with ESC)
        // TODO: handle backspace to delete char (cancel works but isn't enought)
        // TODO: handle history_nb getting > to HISTORY_MAX_NB (cyclic structure ??)
        // for now the program just crashes

        switch (code) {
            case '\n':
            case KEY_ENTER:
                if (current_command.empty()) {
                    clear();
                    reset();
                    return;
                }
                history.push_back(current_command);
                clear();
                exec_command_callback(current_command);
                reset();
                return;

            case KEY_DC:
                delete_char();
                print_current_command();
                break;

            case KEY_LEFT:
                if (command_cursor > 0) {
                    wmove(window, 0, (--command_cursor)+1);
                    wrefresh(window);
                }
                break;

            case KEY_RIGHT:
                if (command_cursor < current_command.length()) {
                    wmove(window, 0, (++command_cursor)+1);
                    wrefresh(window);
                }
                break;

            case KEY_UP:
                if (history_cursor > 0) {
                    set_command(history[--history_cursor]);
                    print_current_command();
                }
                break;

            case KEY_DOWN:
                if (history_cursor < history.size()) {
                    history_cursor++;
                    if (history_cursor < history.size())
                        set_command(history[history_cursor]);
                    else
                        set_command("");
                    print_current_command();
                }
                break;

            default:
                // If we're here then the code is a simple character
                insert_char((char) code);
                print_current_command();
                break;
        }
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
