#include "commands/close.h"
#include "widgets/tabs.h"
#include <ncurses.h>


void commands_close_exec(char *parameters)
{
    widgets_tabs_close_current_tab();
}
