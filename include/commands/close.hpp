#ifndef __COMMANDS_CLOSE_HPP__
#define __COMMANDS_CLOSE_HPP__

#include <string>

class App;

namespace Commands {
    int close_exec(App *app, int argc, char **argv, std::string *error_message);
}

#endif
