#include "commands/quit.h"
#include "controller.h"



void commands_quit_exec(int argc, char **argv)
{
    // Actually freeing memory before exiting
    controller_free();
    exit(0);
}
