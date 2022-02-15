#ifndef __COMMANDS_TAB_HPP__
#define __COMMANDS_TAB_HPP__

#include <string>

class App;

namespace Commands {
    int tab_move_exec(App *app, int argc, char **argv, std::string *error_message);
    int tab_next_exec(App *app, int argc, char **argv, std::string *error_message);
    int tab_prev_exec(App *app, int argc, char **argv, std::string *error_message);
    void tab_move(App *app, uint8_t new_index);
    void tab_prev(App *app);
    void tab_next(App *app);
}

#endif
