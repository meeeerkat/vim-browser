#ifndef __WIDGETS_TABS_HPP__
#define __WIDGETS_TABS_HPP__

#include <ncurses.h>
#include "model/page.hpp"

#define TABS_MAX_NB 10

namespace TabsWidget {
    void init(void (*update_page_display_callback) (Page*));
    void free();

    Page *get_tab_page(uint8_t tab_index);
    Page *get_displayed_page();
    int8_t add_tab(Page *new_page);
    bool can_add_tab();
    int8_t set_current_tab_index(uint8_t new_tab_index);
    uint8_t get_current_tab_index();
    uint8_t get_pages_nb();

    void close_current_tab();
    void close_tab(uint8_t tab_index);

    void update_view();
};

#endif
