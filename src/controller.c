#include "controller.h"
#include "view.h"
#include "widgets/tabs_widget.h"
#include "widgets/page_widget.h"
#include "widgets/command_widget.h"


void controller_init()
{
    view_init();

    model_init();
    tabs_widget_init();
    page_widget_init();
    command_widget_init();
}

void controller_free()
{
    model_free();
    tabs_widget_free();
    page_widget_free();
    command_widget_free();

    view_close();
}

int8_t controller_open_in_current_tab(char *url)
{
    page_t *current_page = tabs_widget_get_displayed_page();
    if (model_load_page(url, current_page) < 0)
        return -1;

    page_widget_display(current_page);

    return 0;
}

int8_t controller_open_in_new_tab(char *url)
{
    page_t *new_page = tabs_widget_add_tab();
    if (model_load_page(url, new_page) < 0)
        return -1;
    return 0;
}
