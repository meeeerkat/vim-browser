#include "controller.h"
#include "widgets/tabs_widget.h"
#include "widgets/page_widget.h"
#include "widgets/command_widget.h"
#include "input_handler.h"


void controller_init()
{
    // ncurses init
    initscr();

    // widgets init
    tabs_widget_init();
    page_widget_init();
    command_widget_init();

    // helpers init
    model_init();
    input_handler_init();

    input_handler_wait_and_read();
}

void controller_free()
{
    // helpers freeing
    input_handler_free();
    model_free();

    // widgets freeing
    tabs_widget_free();
    page_widget_free();
    command_widget_free();

    // ncurses closing
    endwin();
}

int8_t controller_open_in_current_tab(char *url)
{
    page_t *current_page = tabs_widget_get_displayed_page();
    if (model_load_page(url, current_page) < 0)
        return -1;

    page_widget_display(current_page);

    return 0;
}

int8_t controller_open_in_new_tab(char *url)
{
    page_t *new_page = tabs_widget_add_tab();
    if (model_load_page(url, new_page) < 0)
        return -1;
    return 0;
}
