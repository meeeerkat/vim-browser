#include "widgets/page.hpp"

namespace PageWidget {
    namespace {
        WINDOW *window;
    }

    void init()
    {
        window = subpad(stdscr, LINES-3, COLS, 0, 0);
        keypad(window, TRUE);
    }

    void free()
    {
        delwin(window);
    }

    void display(Page *page)
    {
        // TODO: make the page here
    }

    void handle_input()
    {

    }
}
