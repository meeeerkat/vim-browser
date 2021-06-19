#include "widgets/page.h"

static WINDOW *window = NULL;

void widgets_page_init()
{
    // Takes all but the first and last lines
    window = newwin(LINES-2, COLS, 1, 0);
    keypad(window, TRUE);
}

void widgets_page_free()
{
    delwin(window);
    window = NULL;
}

void widgets_page_display(model_page_t *page)
{
    // TODO: make the page here
    wrefresh(window);
}

void widgets_page_handle_input()
{

}
