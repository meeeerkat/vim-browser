#include "commands/open.h"
#include "controller.h"


void commands_open_exec(char *parameters)
{
    controller_open_in_new_tab("https://www.duckduckgo.com");
}

