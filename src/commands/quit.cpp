#include <stdlib.h>
#include <glib.h>
#include "commands/quit.hpp"
#include "controller.hpp"



namespace Commands {
    int quit_exec(int, char **argv, std::string *)
    {
        g_strfreev(argv);
        delete Controller::instance;
        exit(EXIT_SUCCESS);
        return 0;
    }
}
