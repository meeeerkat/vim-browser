#include "widgets/page_widget.h"

static WINDOW *window = NULL;

void page_widget_init()
{
    // Takes all but the first and last lines
    window = newwin(LINES-2, COLS, 1, 0);
}

void page_widget_free()
{
    delwin(window);
    window = NULL;
}

void page_widget_display(page_t *page)
{
    // TODO: make the page here
    wrefresh(window);
}

void page_widget_prepare_input_handling()
{

}
bool page_widget_handle_input(int16_t c)
{
    return false;
}
