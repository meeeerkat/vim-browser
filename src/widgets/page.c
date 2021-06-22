#include "widgets/page.h"


typedef struct widgets_page_data {
    WINDOW *pad;
} widgets_page_data_t;

static widgets_page_data_t data;

void widgets_page_init()
{
    data.pad = subpad(stdscr, LINES-3, COLS, 0, 0);
    keypad(data.pad, TRUE);
}

void widgets_page_free()
{
    delwin(data.pad);
    data.pad = NULL;
}

void widgets_page_display(model_page_t *page)
{
    // TODO: make the page here
}

void widgets_page_handle_input()
{

}
