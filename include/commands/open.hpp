#ifndef __COMMANDS_OPEN_HPP__
#define __COMMANDS_OPEN_HPP__

#include <string>

namespace Commands {
    void open_exec(int argc, char **argv);
    void open_in_current_tab(std::string url);
    void open_in_new_tab(std::string url);
}

#endif
