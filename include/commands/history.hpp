#ifndef __COMMANDS_HISTORY_HPP__
#define __COMMANDS_HISTORY_HPP__

#include <string>

class App;

namespace Commands {
    int history_exec(App *app, int argc, char **argv, std::string *error_message);
}

#endif
