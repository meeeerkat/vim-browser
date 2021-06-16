#include "widgets/tabs_widget.h"

#define MAX_TABS_INDEX 10

typedef struct data {
    WINDOW *window;
    page_t **pages;
    uint8_t current_tab_index;
    uint8_t tabs_nb;
} data_t;

static data_t data;

static void update_view();


void tabs_widget_init()
{
    // Takes only the first line
    data.window = newwin(1, COLS, 0, 0);
    data.pages = malloc(sizeof(page_t*) * MAX_TABS_INDEX);
    data.tabs_nb = 0;
    data.current_tab_index = 0;
    // There is only a tab at startup (an empty one for now)
    tabs_widget_add_tab();
}
void tabs_widget_free()
{
    for (uint8_t i=0; i < data.tabs_nb; i++)
        page_free(data.pages[i]);
    free(data.pages);

    delwin(data.window);
}

page_t *tabs_widget_get_displayed_page()
{
    return data.pages[data.current_tab_index];
}

page_t *tabs_widget_add_tab()
{
    page_t *new_page = page_init();
    data.pages[data.tabs_nb] = new_page;
    data.tabs_nb++;
    update_view();
    return new_page;
}
void tabs_widget_set_current_tab(uint8_t new_tab_index)
{
    data.current_tab_index = new_tab_index;
    update_view();
}

void update_view()
{
    wclear(data.window);

    const uint8_t tab_size = COLS/data.tabs_nb;
    for (uint8_t i=0; i < data.tabs_nb; i++)
        mvwprintw(data.window, 0, i*tab_size, "%hhu", i);

    wrefresh(data.window);
}
