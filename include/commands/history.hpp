#ifndef __COMMANDS_HISTORY_HPP__
#define __COMMANDS_HISTORY_HPP__

#include <string>

namespace Commands {
    int history_exec(int argc, char **argv, std::string *error_message);
}

#endif
