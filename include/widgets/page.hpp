#ifndef __WIDGETS_PAGE_HPP__
#define __WIDGETS_PAGE_HPP__

#include <stdint.h>
#include "model/nodes/interactive_element.hpp"

class Document;

namespace PageWidget {
    void init();
    void free();
    void display(Document *doc, uint32_t start_line = 0);
    Document *get_displayed_document();
    void scroll_to(uint32_t start_line);
    void refresh_display();
    void refresh_display(Nodes::PrintingOptions new_options);
    uint32_t get_start_line();
    
    int interact(uint8_t type, std::string *error_message);
};

#endif
