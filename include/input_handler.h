#ifndef __INPUT_HANDLER_H__
#define __INPUT_HANDLER_H__

#include <ncurses.h>

void input_handler_init();
void input_handler_free();
void input_handler_wait_and_read();

#endif
