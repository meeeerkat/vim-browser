#include "commands/quit.h"
#include "controller.h"



void commands_quit_exec(char *parameters)
{
    // Actually freeing memory before exiting
    controller_free();
    exit(0);
}
