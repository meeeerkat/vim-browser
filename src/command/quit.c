#include "controller.h"
#include "command/quit.h"



void command_quit_exec(char *parameters)
{
    // Actually freeing memory before exiting
    controller_free();
    exit(0);
}
