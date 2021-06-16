#ifndef __COMMAND_WIDGET_H__
#define __COMMAND_WIDGET_H__

#include <ncurses.h>

void command_widget_init();
void command_widget_free();

// input handling
void command_widget_prepare_input_handling();
bool command_widget_handle_input(int16_t c);

#endif
