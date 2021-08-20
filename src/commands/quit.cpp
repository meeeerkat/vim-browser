#include <stdlib.h>
#include <glib.h>
#include "commands/quit.hpp"
#include "controller.hpp"



namespace Commands {
    int quit_exec(int, char **, std::string *)
    {
        Controller::quit_when_possible();
        return 0;
    }
}
