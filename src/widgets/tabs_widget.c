#include "widgets/tabs_widget.h"

#define MAX_TABS_INDEX 10

typedef struct data {
    WINDOW *window;
    page_t **pages;
    uint8_t current_tab_index;
    uint8_t tabs_nb;
} data_t;

static data_t data;


void tabs_widget_init()
{
    // Takes only the first line
    data.window = newwin(1, COLS, 0, 0);
    data.pages = malloc(sizeof(page_t*) * MAX_TABS_INDEX);
    // There is only a tab at startup (an empty one for now)
    data.current_tab_index = 0;
    data.tabs_nb = 1;
    data.pages[0] = page_init();
}
void tabs_widget_free()
{
    for (uint8_t i=0; i < data.tabs_nb; i++)
        page_free(data.pages[i]);
    free(data.pages);

    delwin(data.window);
}

page_t *tabs_widget_current_page()
{
    return data.pages[data.current_tab_index];
}
