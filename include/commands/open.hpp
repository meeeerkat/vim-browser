#ifndef __COMMANDS_OPEN_HPP__
#define __COMMANDS_OPEN_HPP__

#include <string>
#include "helpers/http_request.hpp"

class App;

namespace Commands {
    int open_exec(App *app, int argc, char **argv, std::string *error_message);

    void open(App *app, const Helpers::HttpRequest &request, bool in_new_tab = false);
    void open_in_current_tab(App *app, const Helpers::HttpRequest &request);
    void open_in_new_tab(App *app, const Helpers::HttpRequest &request);
}

#endif
