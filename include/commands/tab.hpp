#ifndef __COMMANDS_TAB_HPP__
#define __COMMANDS_TAB_HPP__

#include <string>

namespace Commands {
    int tab_move_exec(int argc, char **argv, std::string *error_message);
    int tab_next_exec(int argc, char **argv, std::string *error_message);
    int tab_prev_exec(int argc, char **argv, std::string *error_message);
    void tab_move(uint8_t new_index);
    void tab_prev();
    void tab_next();
}

#endif
