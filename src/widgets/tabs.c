#include "widgets/tabs.h"
#include "model/page.h"

#define TABS_MAX_NB 10

typedef struct data {
    WINDOW *window;
    model_page_t **pages;
    uint8_t current_tab_index;
    uint8_t tabs_nb;
    void (*update_page_display_callback) (model_page_t*);
} data_t;


// Private declarations
static data_t data;


void widgets_tabs_init(void (*update_page_display_callback) (model_page_t*))
{
    // Takes only the first line
    data.window = newwin(1, COLS, 0, 0);
    data.pages = malloc(sizeof(model_page_t*) * TABS_MAX_NB);
    data.tabs_nb = 0;
    data.current_tab_index = 0;
    data.update_page_display_callback = update_page_display_callback;

    widgets_tabs_add_tab();
}
void widgets_tabs_free()
{
    for (uint8_t i=0; i < data.tabs_nb; i++)
        model_page_free(data.pages[i]);
    free(data.pages);

    delwin(data.window);
}

model_page_t *widgets_tabs_get_tab_page(uint8_t tab_index)
{
    return data.pages[tab_index];
}

model_page_t *widgets_tabs_get_displayed_page()
{
    return widgets_tabs_get_tab_page(data.current_tab_index);
}

int8_t widgets_tabs_add_tab()
{
    if (data.tabs_nb == TABS_MAX_NB)
        return -1;

    data.pages[data.tabs_nb++] = model_page_init();
    widgets_tabs_update_view();
    return data.tabs_nb-1;
}
int8_t widgets_tabs_set_current_tab_index(uint8_t new_tab_index)
{
    if (new_tab_index >= data.tabs_nb)
        return -1;
    data.current_tab_index = new_tab_index;
    widgets_tabs_update_view();

    return 0;
}
uint8_t widgets_tabs_get_current_tab_index()
{
    return data.current_tab_index;
}

void widgets_tabs_update_view()
{
    wclear(data.window);

    const uint16_t tab_size = COLS/data.tabs_nb;
    for (uint8_t i=0; i < data.tabs_nb; i++) {
        const char *title = model_page_get_title(data.pages[i]);
        if (title == NULL)
            mvwprintw(data.window, 0, i*tab_size, "%hhu: Loading...", i);
        else
            mvwprintw(data.window, 0, i*tab_size, "%hhu: %s", i, title);
    }

    wrefresh(data.window);
}

void widgets_tabs_close_current_tab()
{
    widgets_tabs_close_tab(data.current_tab_index);
}

void widgets_tabs_close_tab(uint8_t tab_index)
{
    // Always keep one tab opened
    if (data.tabs_nb == 1)
        return;

    for (uint8_t i=tab_index; i < data.tabs_nb; i++)
        data.pages[i] = data.pages[i+1];
    data.tabs_nb--;

    // Not changing the current tab's page if it's not the one deleted
    if (data.current_tab_index > tab_index)
        data.current_tab_index--;
    // If it's the one deleted, the next one is displayed except if it's the last one
    else if(data.current_tab_index == tab_index && data.current_tab_index == data.tabs_nb) {
        data.current_tab_index--;
        data.update_page_display_callback(data.pages[data.current_tab_index]);
    }
    
    widgets_tabs_update_view();
}

