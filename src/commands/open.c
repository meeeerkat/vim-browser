#include "commands/open.h"
#include "model/loader.h"
#include "widgets/page.h"
#include "widgets/tabs.h"


void commands_open_exec(char *parameters)
{
    commands_open_in_new_tab("https://www.duckduckgo.com");
}



void commands_open_in_current_tab(char *url)
{
    model_page_t *current_page = widgets_tabs_get_displayed_page();
    model_loader_load_page_async(url, current_page, (void (*) (void*))widgets_page_display, current_page);
}
void commands_open_in_new_tab(char *url)
{
    model_page_t *new_page = widgets_tabs_add_tab();
    model_loader_load_page_async(url, new_page, (void (*) (void*))widgets_page_display, new_page);
}
