#ifndef __COMMANDS_OPEN_HPP__
#define __COMMANDS_OPEN_HPP__

#include <string>

namespace Commands {
    int open_exec(int argc, char **argv, std::string *error_message);
    void open_in_current_tab(std::string url);
    void open_in_new_tab(std::string url);
}

#endif
