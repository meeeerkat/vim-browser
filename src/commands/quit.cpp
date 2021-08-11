#include <stdlib.h>
#include "commands/quit.hpp"
#include "controller.hpp"



namespace Commands {
    int quit_exec(int, char **, std::string *)
    {
        delete Controller::instance;
        exit(EXIT_SUCCESS);
        return 0;
    }
}
