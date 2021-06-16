#include <ncurses.h>
#include "view.h"


void view_init()
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
}

void view_close()
{
    endwin();
}
