#ifndef __WIDGETS_TABS_H__
#define __WIDGETS_TABS_H__

#include <ncurses.h>
#include "model/page.h"

void widgets_tabs_init();
void widgets_tabs_free();

model_page_t *widgets_tabs_get_displayed_page();
model_page_t *widgets_tabs_add_tab();
void widgets_tabs_set_current_tab(uint8_t new_tab_index);

void widgets_tabs_close_current_tab();
void widgets_tabs_close_tab(uint8_t tab_index);

#endif
