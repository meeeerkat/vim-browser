#include <ncurses.h>
#include <ctype.h>
#include "widgets/page.hpp"
#include "model/document.hpp"

namespace PageWidget {
    namespace {
        WINDOW *pad;
        // displayed_document isn't owned by PageWidget
        Document *displayed_document;
        uint32_t start_line;
        Nodes::PrintingOptions printing_options;

        const uint32_t MAX_LINES_NB = 5000;
    }

    void init()
    {
        pad = newpad(MAX_LINES_NB, COLS);
        keypad(pad, TRUE);

        displayed_document = NULL;
    }

    void free()
    {
        delwin(pad);
    }

    void display(Document *doc, uint32_t start_line_p)
    {
        displayed_document = doc;

        // Printing doc
        start_line = start_line_p;
        refresh_display();
    }

    Document *get_displayed_document()
    {
        return displayed_document;
    }

    void scroll_to(uint32_t start_line_p)
    {
        if (start_line_p > MAX_LINES_NB)
            return;

        start_line = start_line_p;
        prefresh(pad, start_line, 0, 1, 0, LINES-2, COLS);
    }

    void refresh_display()
    {
        wclear(pad);
        displayed_document->printw(pad, printing_options);
        prefresh(pad, start_line, 0, 1, 0, LINES-2, COLS);
    }
    
    void refresh_display(Nodes::PrintingOptions new_options)
    {
        printing_options = new_options;
        refresh_display();
    }

    uint32_t get_start_line()
    {
        return start_line;
    }

    int interact(uint8_t type, std::string *error_message)
    {
        // Printing doc showing interactions
        printing_options = Nodes::PrintingOptions{true, ""};
        refresh_display();

        // Handling input to choose the element
        uint16_t c = wgetch(pad);
        while (isdigit(c)) {
            printing_options.interaction_current_id += c;
            refresh_display();
            c = wgetch(pad);
        }

        if (c == '\n' || c == KEY_ENTER) {
            Nodes::InteractiveElement *el = displayed_document->get_interactive_element(printing_options.interaction_current_id);
            if (el != NULL)
                el->interact(type);
            else {
                refresh_display(Nodes::PrintingOptions{});
                *error_message = "Id not found.";
                return -1;
            }

        }

        refresh_display(Nodes::PrintingOptions{});
        return 0;
    }
}
