#include "commands/close.h"
#include "widgets/tabs.h"
#include <ncurses.h>


void commands_close_exec(int argc, char **argv)
{
    widgets_tabs_close_current_tab();
}
