#ifndef __WIDGETS_COMMAND_H__
#define __WIDGETS_COMMAND_H__

#include <ncurses.h>

void widgets_command_init(void (*exec_command_callback) (char*));
void widgets_command_free();

// input handling
void widgets_command_handle_input();

#endif
