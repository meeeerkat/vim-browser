#include "command/open.h"
#include "controller.h"


void command_open_exec(char *parameters)
{
    controller_open_in_new_tab("https://www.duckduckgo.com");
}

