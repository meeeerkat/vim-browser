#ifndef __COMMANDS_INTEERACT_HPP__
#define __COMMANDS_INTERACT_HPP__

#include <string>

namespace Commands {
    int interact_exec(int argc, char **argv, std::string *error_message);
}

#endif
