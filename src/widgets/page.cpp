#include "widgets/page.hpp"
#include "model/document.hpp"

namespace PageWidget {
    namespace {
        WINDOW *window;
        // displayed_document isn't owned by PageWidget
        Document *displayed_document;
    }

    void init()
    {
        window = newwin(LINES-2, COLS, 1, 0);
        keypad(window, TRUE);

        displayed_document = NULL;
    }

    void free()
    {
        delwin(window);
    }

    void display(Document *doc)
    {
        displayed_document = doc;

        // Printing doc
        wclear(window);
        displayed_document->printw(window);
        wrefresh(window);
    }

    void handle_input()
    {

    }
    
    Document *get_displayed_document()
    {
        return displayed_document;
    }
}
