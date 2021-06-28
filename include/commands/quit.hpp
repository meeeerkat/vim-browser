#ifndef __COMMANDS_QUIT_HPP__
#define __COMMANDS_QUIT_HPP__

#include <string>

namespace Commands {
    int quit_exec(int argc, char **argv, std::string *error_message);
}

#endif
