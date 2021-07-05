#ifndef __WIDGETS_TABS_HPP__
#define __WIDGETS_TABS_HPP__

#include <ncurses.h>
#include "model/document.hpp"

#define TABS_MAX_NB 10

namespace TabsWidget {
    void init();
    void free();

    Document *get_document(uint8_t tab_index);
    Document *get_current_document();
    int8_t add_tab(Document *new_tab, uint8_t tab_index);
    bool can_add_tab();
    void replace_document(Document *new_doc, uint8_t tab_index);
    int8_t set_current_tab_index(uint8_t new_tab_index);
    int8_t get_current_tab_index();
    uint8_t get_tabs_nb();

    int close_current_tab();
    int close_tab(uint8_t tab_index);

    void update_view();
};

#endif
