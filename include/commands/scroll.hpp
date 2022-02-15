#ifndef __COMMANDS_SCROLL_HPP__
#define __COMMANDS_SCROLL_HPP__

#include <string>

class App;

namespace Commands {
    int scroll_exec(App *app, int argc, char **argv, std::string *error_message);
}

#endif
