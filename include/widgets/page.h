#ifndef __WIDGETS_PAGE_H__
#define __WIDGETS_PAGE_H__

#include <ncurses.h>
#include "model/page.h"

void widgets_page_init();
void widgets_page_free();
void widgets_page_display(model_page_t *page);

// input handling
void widgets_page_handle_input();

#endif
