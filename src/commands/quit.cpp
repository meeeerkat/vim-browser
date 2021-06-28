#include <stdlib.h>
#include "commands/quit.hpp"
#include "controller.hpp"



namespace Commands {
    int quit_exec(int argc, char **argv, std::string *error_message)
    {
        // Actually freeing memory before exiting
        Controller::free();
        exit(0);
        return 0;
    }
}
