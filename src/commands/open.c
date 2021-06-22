#include <unistd.h>
#include "commands/open.h"
#include "widgets/page.h"
#include "widgets/tabs.h"
#include "helpers.h"


static void on_page_loaded(uint8_t *tab_index);

void commands_open_exec(int argc, char **argv)
{
    bool new_tab = false;
    char opt;
    // getopt config
    opterr = 0; // No errors on stderr
    optind = 0; // Reset getopt cursor (need to do it every time)
    while ((opt = getopt(argc, argv, "t")) != -1) {
        switch (opt) {
            case 't':
                new_tab = true;
                break;
            default:
        }
    }
    if (optind >= argc)
        return;
    char *url = helpers_url_fix(argv[optind]);

    if (new_tab)
        commands_open_in_new_tab(url);
    else
        commands_open_in_current_tab(url);

    free(url);
}



void commands_open_in_current_tab(char *url)
{
    uint8_t current_page_tab_index = widgets_tabs_get_current_tab_index();
    model_page_t *current_page = widgets_tabs_get_displayed_page();
    model_page_set_url_and_load(current_page, url, (void (*) (void*))on_page_loaded, &current_page_tab_index);
}
void commands_open_in_new_tab(char *url)
{
    uint8_t new_page_tab_index = widgets_tabs_add_tab();
    widgets_tabs_set_current_tab_index(new_page_tab_index);
    model_page_t *new_page = widgets_tabs_get_displayed_page();
    model_page_set_url_and_load(new_page, url, (void (*) (void*))on_page_loaded, &new_page_tab_index);
}

void on_page_loaded(uint8_t *tab_index)
{
    widgets_page_display(widgets_tabs_get_tab_page(*tab_index));
    // Updating tabs because the page's title is now set
    widgets_tabs_update_view();
}
