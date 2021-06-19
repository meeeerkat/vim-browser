#include <string.h>
#include <pthread.h>
#include "controller.h"
#include "widgets/tabs.h"
#include "widgets/page.h"
#include "widgets/command.h"
#include "input_handler.h"


void controller_init()
{
    // ncurses init
    initscr();

    // helpers init
    model_loader_init();
    input_handler_init();

    // widgets init
    widgets_tabs_init();
    widgets_page_init();
    widgets_command_init();

    controller_open_in_current_tab("https://duckduckgo.com");

    // Setup complete, now everything is done after an user command
    input_handler_wait_and_read();
}

void controller_free()
{
    // helpers freeing
    input_handler_free();
    model_loader_free();

    // widgets freeing
    widgets_tabs_free();
    widgets_page_free();
    widgets_command_free();

    // ncurses closing
    endwin();
}

void controller_open_in_current_tab(char *url)
{
    model_page_t *current_page = widgets_tabs_get_displayed_page();
    model_loader_load_page_async(url, current_page, (void (*) (void*))widgets_page_display, current_page);
}

void controller_open_in_new_tab(char *url)
{
    model_page_t *new_page = widgets_tabs_add_tab();
    model_loader_load_page_async(url, new_page, (void (*) (void*))widgets_page_display, new_page);
}

