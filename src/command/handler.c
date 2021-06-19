#include <inttypes.h>
#include <string.h>
#include "command/handler.h"
#include "command/quit.h"
#include "command/open.h"



typedef struct command {
    char *name;
    void (*exec) (char*);
} command_t;


#define COMMAND(NAME)  { #NAME, command_ ## NAME ## _exec }
static const command_t COMMANDS[] = 
{
    COMMAND(quit),
    COMMAND(open),
};
static const uint16_t COMMANDS_NB = 2;


void command_handler_exec(char *command)
{
    char name[COMMAND_NAME_MAX_LENGTH];
    char parameters[COMMAND_MAX_LENGTH];
    uint16_t i;
    for (i=0; i < COMMAND_NAME_MAX_LENGTH && command[i] != ' '; i++);
    memcpy(name, command, i);
    strcpy(parameters, command+i); // Copies the rest of the string

    for (i=0; i < COMMANDS_NB && strcmp(name, COMMANDS[i].name) != 0; i++);

    if (i < COMMANDS_NB)
        COMMANDS[i].exec(parameters);
}
