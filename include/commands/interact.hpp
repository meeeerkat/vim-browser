#ifndef __COMMANDS_INTEERACT_HPP__
#define __COMMANDS_INTERACT_HPP__

#include <string>

class App;

namespace Commands {
    int interact_exec(App *app, int argc, char **argv, std::string *error_message);
}

#endif
