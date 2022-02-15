#ifndef __COMMANDS_WRITECOMMAND_HPP__
#define __COMMANDS_WRITECOMMAND_HPP__

#include <string>

class App;

namespace Commands {
    int write_command_exec(App *app, int argc, char **argv, std::string *error_message);
}

#endif
