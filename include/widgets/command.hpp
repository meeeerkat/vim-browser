#ifndef __WIDGETS_COMMAND_HPP__
#define __WIDGETS_COMMAND_HPP__

#include <ncurses.h>
#include <string>
#include "commands/handler.hpp"


namespace CommandWidget {
    void init(int (*exec_command_callback) (std::string));
    void free();
    void handle_input();
    void print_message(std::string message);
};

#endif
