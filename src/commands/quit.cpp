#include <stdlib.h>
#include "commands/quit.hpp"
#include "controller.hpp"



namespace Commands {
    void quit_exec(int argc, char **argv)
    {
        // Actually freeing memory before exiting
        Controller::free();
        exit(0);
    }
}
