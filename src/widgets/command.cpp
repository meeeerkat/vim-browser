#include <vector>
#include "widgets/command.hpp"

#define KEY_OTHER_ENTER 10


namespace CommandWidget {
    namespace {
        WINDOW *window;
        std::string current_command; // Current command cache
        uint16_t command_cursor; // Cursor position in the current command
        std::vector<std::string> history; // History cache
        uint16_t history_cursor; // Currently displayed history command
        int (*exec_command_callback) (std::string);
    }
    void print_current_command();
    void reset();
    void insert_char(char c);
    void delete_char();
    void set_command(std::string command);


    void init(int (*exec_command_callback_p) (std::string))
    {
        exec_command_callback = exec_command_callback_p;

        // Takes only the last line
        window = newwin(1, COLS, LINES-1, 0);
        keypad(window, TRUE);

        reset();
    }
    void free()
    {
        delwin(window);
    }




    // Inputs
    void reset()
    {
        command_cursor = 0;
        current_command = "";
        history_cursor = history.size();
    }
    void clear()
    {
        wclear(window);
        wrefresh(window);
    }

    void print_current_command()
    {
        wclear(window);
        // noecho mode so need to reprint the character where it's needed
        mvwprintw(window, 0, 0, ":%s", current_command.c_str());
        wmove(window, 0, command_cursor+1);

        wrefresh(window);
    }

    void insert_char(char c)
    {
        current_command.insert(command_cursor, 1, c);
        command_cursor++;
    }

    void delete_char()
    {
        if (command_cursor < current_command.length())
            current_command.erase(command_cursor, 1);
        else if (command_cursor == current_command.length() && current_command.length() > 0) {
            current_command.erase(command_cursor-1, 1);
            command_cursor--;
        }
    }

    void set_command(std::string command)
    {
        current_command = command;
        command_cursor = command.length();
    }


    void handle_input()
    {
        wclear(window); // Necessary to clear messages
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
                case KEY_ENTER:
                case KEY_OTHER_ENTER:
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


    void print_message(std::string message)
    {
        wclear(window);
        wprintw(window, "%s", message.c_str());
        wrefresh(window);
    }
}
