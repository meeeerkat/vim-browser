#include "input_handler.h"
#include "widgets/page_widget.h"
#include "widgets/command_widget.h"

#define ESC 27


enum ForwardingTarget{ None, Page, Command };

typedef struct input_handler_data {
    // fake 0 sized window that only serves to get input (wgetch)
    // because wgetch refreshes the window every time it's called
    WINDOW *fake_window;
} input_handler_data_t;

static input_handler_data_t data;


void input_handler_init()
{
    // ncurses inputs init
    data.fake_window = newwin(0, 0, LINES-1, COLS-1);
    raw();
    keypad(data.fake_window, TRUE);
    noecho();
}

void input_handler_free()
{
    delwin(data.fake_window);
}

void input_handler_wait_and_read()
{
    while (TRUE) {
        const uint16_t c = wgetch(data.fake_window);
        /* These ifs only modifies the forwarding target but there are single
        ** press keys that should be passed directly
        ** such as arrow keys to page_widget (to scroll)
        ** These should be set below after the current ifs */
        if (c == 'i')
            page_widget_handle_input();
        else if (c == ':')
            command_widget_handle_input();
        //else if (c in to_forward_to_page) ...
    }
}

