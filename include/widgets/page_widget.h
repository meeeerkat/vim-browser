#ifndef __PAGE_WIDGET_H__
#define __PAGE_WIDGET_H__

#include <ncurses.h>
#include "page.h"

void page_widget_init();
void page_widget_free();
void page_widget_display(page_t *page);

#endif
