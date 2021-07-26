#ifndef __WIDGETS_PAGE_HPP__
#define __WIDGETS_PAGE_HPP__

#include <stdint.h>
#include "model/nodes/interactive_element.hpp"

class Document;

namespace Widgets {
    class Page {
        public:
            Page();
            ~Page();
            void display(Document *doc, uint32_t start_line = 0);
            Document *get_displayed_document();
            void scroll_to(uint32_t start_line);
            void refresh_display();
            void refresh_display(Nodes::PrintingOptions new_options);
            uint32_t get_start_line() const;
            
            int interact(Nodes::PrintingOptions::InteractionType type, std::string *error_message);

        private:
            WINDOW *pad;
            // displayed_document isn't owned by PageWidget
            Document *displayed_document;
            uint32_t start_line;
            Nodes::PrintingOptions printing_options;

            const uint32_t MAX_LINES_NB = 5000;

    };
}

#endif
