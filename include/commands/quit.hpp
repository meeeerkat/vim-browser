#ifndef __COMMANDS_QUIT_HPP__
#define __COMMANDS_QUIT_HPP__

#include <string>

class App;

namespace Commands {
    int quit_exec(App *app, int argc, char **argv, std::string *error_message);
}

#endif
