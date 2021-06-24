#include "input_handler.hpp"
#include "widgets/page.hpp"
#include "widgets/command.hpp"

#define ESC 27

namespace InputHandler {
    namespace {
        WINDOW *fake_window;
    }

    void init()
    {
        // ncurses inputs init
        fake_window = newwin(0, 0, LINES-1, COLS-1);
        raw();
        keypad(fake_window, TRUE);
        noecho();
    }

    void free()
    {
        delwin(fake_window);
    }

    void wait_and_read()
    {
        while (TRUE) {
            const uint16_t c = wgetch(fake_window);
            /* These ifs only modifies the forwarding target but there are single
            ** press keys that should be passed directly
            ** such as arrow keys to page_widget (to scroll)
            ** These should be set below after the current ifs */
            if (c == 'i')
                PageWidget::handle_input();
            else if (c == ':')
                CommandWidget::handle_input();
            //else if (c in to_forward_to_page) ...
        }
    }
}

