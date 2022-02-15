#include <stdlib.h>
#include <glib.h>
#include "commands/quit.hpp"
#include "app.hpp"



namespace Commands {
    int quit_exec(App *app, int, char **, std::string *)
    {
        app->quit_when_possible();
        return 0;
    }
}
