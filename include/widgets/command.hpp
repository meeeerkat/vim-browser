#ifndef __WIDGETS_COMMAND_HPP__
#define __WIDGETS_COMMAND_HPP__

#include <ncurses.h>
#include <string>
#include <vector>
#include "commands/handler.hpp"


namespace Widgets {
    class Command {

        public:
            Command(int (*exec_command_callback) (const std::string&));
            ~Command();
            void handle_input(const std::string *base_command = NULL);
            void print_message(const std::string &message);

        private:
            WINDOW *window;
            std::string current_command; // Current command cache
            uint16_t command_cursor; // Cursor position in the current command
            std::vector<std::string> history; // History cache
            uint16_t history_cursor; // Currently displayed history command
            int (*exec_command_callback) (const std::string&);

            void print_current_command();
            void reset();
            void clear();
            void insert_char(char c);
            void delete_char();
            void set_command(const std::string &command);
    };
}

#endif
