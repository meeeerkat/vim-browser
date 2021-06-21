#ifndef __WIDGETS_TABS_H__
#define __WIDGETS_TABS_H__

#include <ncurses.h>
#include "model/page.h"

void widgets_tabs_init(void (*update_page_display_callback) (model_page_t*));
void widgets_tabs_free();

model_page_t *widgets_tabs_get_tab_page(uint8_t tab_index);
model_page_t *widgets_tabs_get_displayed_page();
int8_t widgets_tabs_add_tab();
int8_t widgets_tabs_set_current_tab_index(uint8_t new_tab_index);
uint8_t widgets_tabs_get_current_tab_index();

void widgets_tabs_close_current_tab();
void widgets_tabs_close_tab(uint8_t tab_index);

void widgets_tabs_update_view();

#endif
