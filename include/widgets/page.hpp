#ifndef __WIDGETS_PAGE_HPP__
#define __WIDGETS_PAGE_HPP__

#include <ncurses.h>

class Document;

namespace PageWidget {
    void init();
    void free();
    void display(Document *doc);
    void handle_input();
    Document *get_displayed_document();
};

#endif
