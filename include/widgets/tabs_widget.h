#ifndef __TABS_WIDGET_H__
#define __TABS_WIDGET_H__

#include <ncurses.h>
#include "page.h"

void tabs_widget_init();
void tabs_widget_free();

page_t *tabs_widget_get_displayed_page();
page_t *tabs_widget_add_tab();
void tabs_widget_set_current_tab(uint8_t new_tab_index);


#endif
