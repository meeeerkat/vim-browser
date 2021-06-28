#ifndef __COMMANDS_TAB_HPP__
#define __COMMANDS_TAB_HPP__

#include <string>

namespace Commands {
    void tab_move_exec(int argc, char **argv);
    void tab_next_exec(int argc, char **argv);
    void tab_prev_exec(int argc, char **argv);
    void tab_move(uint8_t new_index);
    void tab_prev();
    void tab_next();
}

#endif
