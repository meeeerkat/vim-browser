#include "widgets/tabs_widget.h"

#define TABS_MAX_NB 10

typedef struct data {
    WINDOW *window;
    page_t **pages;
    uint8_t current_tab_index;
    uint8_t pages_nb;
} data_t;


// Private declarations
static data_t data;
static void update_view();


void tabs_widget_init()
{
    // Takes only the first line
    data.window = newwin(1, COLS, 0, 0);
    data.pages = malloc(sizeof(page_t*) * TABS_MAX_NB);
    data.pages_nb = 0;
    data.current_tab_index = 0;

    tabs_widget_add_tab();
}
void tabs_widget_free()
{
    for (uint8_t i=0; i < data.pages_nb; i++)
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
    if (data.pages_nb == TABS_MAX_NB)
        return NULL;

    page_t *new_page = page_init();
    data.pages[data.pages_nb++] = new_page;
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

    const uint16_t tab_size = COLS/data.pages_nb;
    for (uint8_t i=0; i < data.pages_nb; i++)
        mvwprintw(data.window, 0, i*tab_size, "%hhu", i);

    wrefresh(data.window);
}
