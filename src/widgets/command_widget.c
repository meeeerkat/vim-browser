#include <stdlib.h>
#include "widgets/command_widget.h"

#define MAX_COMMAND_LENGTH 1000
#define KEY_OTHER_ENTER 10



typedef struct command_widget_data {
    WINDOW *window;
    char current_command[MAX_COMMAND_LENGTH];
    uint16_t command_cursor;
} command_widget_data_t;

static command_widget_data_t data;

void command_widget_init()
{
    data.command_cursor = 0;

    // Takes only the last line
    data.window = newwin(1, COLS, LINES-1, 0);
}
void command_widget_free()
{
    delwin(data.window);
}


// Inputs
static void leave_focus()
{
    data.command_cursor = 0;
    wclear(data.window);
    wrefresh(data.window);
}

void command_widget_prepare_input_handling()
{
    waddch(data.window, ':');
    wrefresh(data.window);
}
bool command_widget_handle_input(int16_t code)
{
    // TODO: handle ESC to leave command input forwarding
    // (or another key since ncurses seems to have problems with ESC)


    if (code == KEY_ENTER || code == KEY_OTHER_ENTER) {
        // Dirty temporary setup to be able to quit easily
        // TODO: actual parsing of the command and execute it (maybe not in this module ??)
        if (data.current_command[0] == 'q') {
            endwin();
            exit(0);
        }
        leave_focus();
        return false;
    }
    // TODO: check if the code is an arrow key (up/down to navigate history,
    // left/right to navigate current command)

    data.current_command[data.command_cursor] = (char) code;
    data.command_cursor++;
    // noecho mode so need to reprint the character where it's needed
    waddch(data.window, (char) code);

    wrefresh(data.window);

    return true;
}
