#include "input_handler.h"
#include "widgets/page_widget.h"
#include "widgets/command_widget.h"

#define ESC 27


enum ForwardingTarget{ None, Page, Command };

typedef struct input_handler_data {
    // fake 0 sized window that only serves to get input (wgetch)
    // because wgetch refreshes the window every time it's called
    WINDOW *fake_window;
    enum ForwardingTarget forwarding_target;
} input_handler_data_t;

static input_handler_data_t data;


void input_handler_init()
{
    // ncurses inputs init
    data.fake_window = newwin(0, 0, LINES-1, COLS-1);
    raw();
    keypad(stdscr, TRUE);
    noecho();
    
    data.forwarding_target = None;
}
void input_handler_free()
{
    delwin(data.fake_window);
}

void input_handler_wait_and_read()
{
    while (TRUE) {
        const uint16_t c = wgetch(data.fake_window);
        if (c == ESC)
            data.forwarding_target = None;

        // handle_input functions return false is they are done and don't want
        // anymore inputs
        if (data.forwarding_target == Page && !page_widget_handle_input(c))
            data.forwarding_target = None;
        else if(data.forwarding_target == Command && !command_widget_handle_input(c))
            data.forwarding_target = None;

        if (data.forwarding_target != None)
            continue;

        /* These ifs only modifies the forwarding target but there are single
        ** press keys that should be passed directly
        ** such as arrow keys to page_widget (to scroll)
        ** These should be set below after the current ifs */
        if (c == 'i') {
            data.forwarding_target = Page;
            page_widget_prepare_input_handling();
        }
        else if (c == ':') {
            data.forwarding_target = Command;
            command_widget_prepare_input_handling();
        }
        //else if (c in to_forward_to_page) ...
    }
}

