#ifndef __COMMANDS_WRITECOMMAND_HPP__
#define __COMMANDS_WRITECOMMAND_HPP__

#include <string>

namespace Commands {
    int write_command_exec(int argc, char **argv, std::string *error_message);
}

#endif
