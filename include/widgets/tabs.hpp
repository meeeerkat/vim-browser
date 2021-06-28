#ifndef __WIDGETS_TABS_HPP__
#define __WIDGETS_TABS_HPP__

#include <ncurses.h>
#include "model/tab.hpp"

#define TABS_MAX_NB 10

namespace TabsWidget {
    void init(void (*display_document_callback) (Document*));
    void free();

    Tab *get_tab(uint8_t tab_index);
    Tab *get_displayed_tab();
    int8_t add_tab(Tab *new_tab);
    bool can_add_tab();
    int8_t set_current_tab_index(uint8_t new_tab_index);
    uint8_t get_current_tab_index();
    uint8_t get_tabs_nb();

    void close_current_tab();
    void close_tab(uint8_t tab_index);

    void update_view();
};

#endif
