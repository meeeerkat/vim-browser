#include <string.h>
#include <pthread.h>
#include "controller.h"
#include "widgets/tabs.h"
#include "widgets/page.h"
#include "widgets/command.h"
#include "input_handler.h"
#include "commands/open.h"


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

    // Opening base window
    commands_open_in_current_tab("https://duckduckgo.com");

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

