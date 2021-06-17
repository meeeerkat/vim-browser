#include <stdlib.h>
#include "widgets/command_widget.h"
#include "command/handler.h"

#define KEY_OTHER_ENTER 10



typedef struct command_widget_data {
    WINDOW *window;
    char current_command[COMMAND_MAX_LENGTH];
    uint16_t command_cursor, command_length;
} command_widget_data_t;

static command_widget_data_t data;


// Private declarations
static void print_command();
static void reset();
static void insert_char(char c);
static void delete_char(int16_t pos);





void command_widget_init()
{
    // Takes only the last line
    data.window = newwin(1, COLS, LINES-1, 0);

    reset();
}
void command_widget_free()
{
    delwin(data.window);
}




// Inputs
void reset()
{
    data.command_cursor = 0;
    data.command_length = 0;
    wclear(data.window);
    wrefresh(data.window);
}

void command_widget_prepare_input_handling()
{
    waddch(data.window, ':');
    wrefresh(data.window);
}

void print_command()
{
    wclear(data.window);
    data.current_command[data.command_length] = '\0';
    // noecho mode so need to reprint the character where it's needed
    mvwprintw(data.window, 0, 0, ":%s", data.current_command);
    wmove(data.window, 0, data.command_cursor+1);

    wrefresh(data.window);
}

void insert_char(char c)
{
    for (int32_t i=data.command_length; i >= data.command_cursor; i--)
        data.current_command[i+1] = data.current_command[i];
    data.current_command[data.command_cursor] = c;

    data.command_cursor++;
    data.command_length++;
}

void delete_char(int16_t pos)
{
    for (uint16_t i=pos; i < data.command_length; i++)
        data.current_command[i] = data.current_command[i+1];

    if (data.command_length > 0) {
        data.command_length--;
        if (data.command_cursor > data.command_length)
            data.command_cursor = data.command_length;
    }
}

bool command_widget_handle_input(int16_t code)
{
    // TODO: handle ESC to leave command input forwarding
    // (or another key since ncurses seems to have problems with ESC)
    // TODO: handle backspace to delete char (cancel works but isn't enought)
    // TODO: handle KEY_UP & KEY_BOTTOM + command history

    switch (code) {
        //case KEY_ENTER:
        case KEY_OTHER_ENTER:
            command_handler_exec(data.current_command);
            reset();
            return false;

        case KEY_DC:
            delete_char(data.command_cursor);
            print_command();
            return true;

        case KEY_LEFT:
            if (data.command_cursor > 0) {
                wmove(data.window, 0, (--data.command_cursor)+1);
                wrefresh(data.window);
            }
            return true;

        case KEY_RIGHT:
            if (data.command_cursor < data.command_length) {
                wmove(data.window, 0, (++data.command_cursor)+1);
                wrefresh(data.window);
            }
            return true;
    }

    // If we're here then the code is a simple character
    insert_char((char) code);
    print_command();

    return true;
}
