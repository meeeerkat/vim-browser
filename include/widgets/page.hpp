#ifndef __WIDGETS_PAGE_HPP__
#define __WIDGETS_PAGE_HPP__

#include <ncurses.h>
#include "model/page.hpp"


namespace PageWidget {
    void init();
    void free();
    void display(Page *page);
    void handle_input();
};

#endif
