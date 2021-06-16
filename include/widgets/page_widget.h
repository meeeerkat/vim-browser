#ifndef __PAGE_WIDGET_H__
#define __PAGE_WIDGET_H__

#include <ncurses.h>
#include "page.h"

void page_widget_init();
void page_widget_free();
void page_widget_display(page_t *page);

// input handling
void page_widget_prepare_input_handling();
bool page_widget_handle_input(int16_t c);

#endif
