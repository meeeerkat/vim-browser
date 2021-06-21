#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "widgets/command.h"
#include "commands/handler.h"

#define KEY_OTHER_ENTER 10
#define HISTORY_MAX_NB 1000 // Quite high because once this limit is reached, the program just crashes



typedef struct widgets_command_data {
    WINDOW *window;
    char current_command[COMMAND_MAX_LENGTH]; // Current command cache
    int16_t command_cursor; // Cursor position in the current command
    uint16_t command_length; // Current command's length
    char history[HISTORY_MAX_NB][COMMAND_MAX_LENGTH]; // History cache
    int16_t history_cursor; // Currently displayed history command
    uint16_t history_nb; // Nb of commands in history
    void (*exec_command_callback) (char*);
} widgets_command_data_t;

static widgets_command_data_t data;


// Private declarations
static void print_current_command();
static void reset();
static void insert_char(char c);
static void delete_char(int16_t pos);
static void set_command(char *command);





void widgets_command_init(void (*exec_command_callback) (char*))
{
    data.history_nb = 0;
    data.exec_command_callback = exec_command_callback;

    // Takes only the last line
    data.window = newwin(1, COLS, LINES-1, 0);
    keypad(data.window, TRUE);

    reset();
}
void widgets_command_free()
{
    delwin(data.window);
}




// Inputs
void reset()
{
    data.command_cursor = 0;
    data.command_length = 0;
    data.history_cursor = data.history_nb;
    wclear(data.window);
    wrefresh(data.window);
}

void print_current_command()
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

void set_command(char *command)
{
    strcpy(data.current_command, command);
    data.command_length = strlen(command);
    data.command_cursor = data.command_length;
}


void widgets_command_handle_input()
{
    waddch(data.window, ':');
    wrefresh(data.window);
    
    while (TRUE) {
        const uint16_t code = wgetch(data.window);
        // TODO: handle ESC to leave command input forwarding
        // (or another key since ncurses seems to have problems with ESC)
        // TODO: handle backspace to delete char (cancel works but isn't enought)
        // TODO: handle history_nb getting > to HISTORY_MAX_NB (cyclic structure ??)
        // for now the program just crashes

        switch (code) {
            case KEY_ENTER:
            case KEY_OTHER_ENTER:
                reset();
                data.history_cursor = data.history_nb;
                strcpy(data.history[data.history_nb++], data.current_command);
                data.exec_command_callback(data.current_command);
                return;

            case KEY_DC:
                delete_char(data.command_cursor);
                print_current_command();
                break;

            case KEY_LEFT:
                if (data.command_cursor > 0) {
                    wmove(data.window, 0, (--data.command_cursor)+1);
                    wrefresh(data.window);
                }
                break;

            case KEY_RIGHT:
                if (data.command_cursor < data.command_length) {
                    wmove(data.window, 0, (++data.command_cursor)+1);
                    wrefresh(data.window);
                }
                break;

            case KEY_UP:
                if (data.history_cursor > 0) {
                    set_command(data.history[--data.history_cursor]);
                    print_current_command();
                }
                break;

            case KEY_DOWN:
                if (data.history_cursor < data.history_nb)
                    set_command(data.history[++data.history_cursor]);
                else if (data.history_cursor == data.history_nb)
                    set_command("");
                print_current_command();
                break;

            default:
                // If we're here then the code is a simple character
                insert_char((char) code);
                print_current_command();
                break;
        }
    }
}


void widgets_command_print_message(char *message)
{
    wclear(data.window);
    wprintw(data.window, "%s", message);
    wrefresh(data.window);
}
