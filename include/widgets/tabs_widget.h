#ifndef __TABS_WIDGET_H__
#define __TABS_WIDGET_H__

#include <ncurses.h>
#include "page.h"

void tabs_widget_init();
void tabs_widget_free();
page_t *tabs_widget_current_page();

#endif
