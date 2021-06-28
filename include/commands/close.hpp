#ifndef __COMMANDS_CLOSE_HPP__
#define __COMMANDS_CLOSE_HPP__

#include <string>

namespace Commands {
    int close_exec(int argc, char **argv, std::string *error_message);
}

#endif
