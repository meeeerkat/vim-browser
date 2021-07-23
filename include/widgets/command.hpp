#ifndef __WIDGETS_COMMAND_HPP__
#define __WIDGETS_COMMAND_HPP__

#include <ncurses.h>
#include <string>
#include "commands/handler.hpp"


namespace CommandWidget {
    void init(int (*exec_command_callback) (const std::string&));
    void free();
    void handle_input(const std::string *base_command = NULL);
    void print_message(const std::string &message);
};

#endif
