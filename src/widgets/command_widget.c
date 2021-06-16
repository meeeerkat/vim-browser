#include "widgets/command_widget.h"

static WINDOW *window = NULL;

void command_widget_init()
{
    // Takes only the last line
    window = newwin(1, COLS, LINES-1, 0);
}
void command_widget_free()
{
    delwin(window);
}
