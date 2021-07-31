#ifndef __WIDGETS_COMMAND_HPP__
#define __WIDGETS_COMMAND_HPP__

#include <ncurses.h>
#include <string>
#include <vector>
#include "widgets/widget.hpp"
#include "model/text_input.hpp"


namespace Widgets {
    class Command : public Widget {

        public:
            Command(int (*exec_command_callback) (const std::string&));
            virtual ~Command();
            void handle_input(const std::string *base_command = NULL);
            void print_message(const std::string &message) const;
            void clear() const;
            void refresh_display() const;

        private:
            WINDOW *window;
            TextInput command;
            std::vector<std::string> history; // History cache
            uint16_t history_cursor; // Currently displayed history command
            int (*exec_command_callback) (const std::string&);

            void reset();
            void insert_char(char c);
            void delete_char();
            void set_command(const std::string &command);
    };
}

#endif
