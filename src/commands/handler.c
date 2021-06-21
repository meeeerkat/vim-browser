#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <glib.h>
#include "commands/handler.h"
#include "commands/quit.h"
#include "commands/open.h"
#include "commands/history.h"
#include "commands/close.h"
#include "helpers.h"



typedef struct command {
    char *name;
    void (*exec) (int, char**);
} command_t;


#define COMMAND(NAME)  { #NAME, commands_ ## NAME ## _exec }
static const command_t COMMANDS[] = 
{
    COMMAND(quit),
    COMMAND(open),
    COMMAND(history),
    COMMAND(close),
};
static const uint16_t COMMANDS_NB = 4;


typedef struct commands_handler_data {
    void (*print_message_callback) (char*);
} commands_handler_data_t;

static commands_handler_data_t data;


void commands_handler_init(void (*print_message_callback) (char*))
{
    data.print_message_callback = print_message_callback;
}

void commands_handler_free()
{

}


void commands_handler_exec(char *command)
{
    int argc = 0;
    char **argv;
    GError *error = NULL;
    g_shell_parse_argv (command, &argc, &argv, &error);

    if (error) {
        data.print_message_callback(error->message);
        g_clear_error(&error);
        return;
    }

    uint16_t i = 0;
    while (i < COMMANDS_NB && strcmp(argv[0], COMMANDS[i].name) != 0)
        i++;

    if (i < COMMANDS_NB)
        COMMANDS[i].exec(argc, argv);
    else
        data.print_message_callback("Unknown command.");
}
