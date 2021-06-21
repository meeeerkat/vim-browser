#ifndef __COMMANDS_HANDLER_H__
#define __COMMANDS_HANDLER_H__

#define COMMAND_NAME_MAX_LENGTH 255
#define COMMAND_MAX_LENGTH 1000

void commands_handler_init(void (*print_message_callback) (char*));
void commands_handler_free();

void commands_handler_exec(char *command);

#endif
