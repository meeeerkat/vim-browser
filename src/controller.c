#include <string.h>
#include <pthread.h>
#include "controller.h"
#include "widgets/tabs_widget.h"
#include "widgets/page_widget.h"
#include "widgets/command_widget.h"
#include "input_handler.h"


void controller_init()
{
    // ncurses init
    initscr();

    // helpers init
    model_init();
    input_handler_init();

    // widgets init
    tabs_widget_init();
    page_widget_init();
    command_widget_init();

    controller_open_in_current_tab("https://duckduckgo.com");

    // Setup complete, now everything is done after an user command
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

void controller_open_in_current_tab(char *url)
{
    page_t *current_page = tabs_widget_get_displayed_page();
    model_load_page_async(url, current_page, (void (*) (void*))page_widget_display, current_page);
}

void controller_open_in_new_tab(char *url)
{
    page_t *new_page = tabs_widget_add_tab();
    model_load_page_async(url, new_page, (void (*) (void*))page_widget_display, new_page);
}

