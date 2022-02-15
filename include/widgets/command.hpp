#ifndef __WIDGETS_COMMAND_HPP__
#define __WIDGETS_COMMAND_HPP__

#include <ncurses.h>
#include <string>
#include <vector>
#include "widgets/widget.hpp"
#include "model/text_input.hpp"

class App;

namespace Widgets {
    class Command : public Widget {

        public:
            Command();
            virtual ~Command();
            void handle_input(App *app, const std::string *base_command = NULL);
            void print_message(const std::string &message) const;
            void clear() const;
            void refresh_display() const;

        private:
            WINDOW *window;
            Model::TextInput command;
            std::vector<std::string> history; // History cache
            uint16_t history_cursor; // Currently displayed history command

            void reset();
            void insert_char(char c);
            void delete_char();
            void set_command(const std::string &command);
    };
}

#endif
