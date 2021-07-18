#include <ncurses.h>
#include "widgets/page.hpp"
#include "model/document.hpp"

namespace PageWidget {
    namespace {
        WINDOW *pad;
        // displayed_document isn't owned by PageWidget
        Document *displayed_document;
        uint32_t start_line;

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
        wclear(pad);
        displayed_document->printw(pad);
        scroll_to(start_line_p);
    }

    void handle_input()
    {

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

    uint32_t get_start_line()
    {
        return start_line;
    }
}
