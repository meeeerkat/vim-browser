#include <stdlib.h>
#include "commands/quit.hpp"
#include "controller.hpp"



namespace Commands {
    int quit_exec(int argc, char **argv, std::string *error_message)
    {
        delete Controller::instance;
        exit(EXIT_SUCCESS);
        return 0;
    }
}
