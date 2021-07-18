#ifndef __WIDGETS_PAGE_HPP__
#define __WIDGETS_PAGE_HPP__

#include <stdint.h>

class Document;

namespace PageWidget {
    void init();
    void free();
    void display(Document *doc, uint32_t start_line = 0);
    void handle_input();
    Document *get_displayed_document();
    void scroll_to(uint32_t start_line);
    uint32_t get_start_line();
};

#endif
