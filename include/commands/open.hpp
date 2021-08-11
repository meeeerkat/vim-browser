#ifndef __COMMANDS_OPEN_HPP__
#define __COMMANDS_OPEN_HPP__

#include <string>
#include "helpers/http_request.hpp"

namespace Commands {
    int open_exec(int argc, char **argv, std::string *error_message);
    void open_in_current_tab(const Helpers::HttpRequest &request);
    void open_in_new_tab(const Helpers::HttpRequest &request);
}

#endif
