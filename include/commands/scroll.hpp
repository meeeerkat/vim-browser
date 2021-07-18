#ifndef __COMMANDS_SCROLL_HPP__
#define __COMMANDS_SCROLL_HPP__

#include <string>

namespace Commands {
    int scroll_exec(int argc, char **argv, std::string *error_message);
}

#endif
