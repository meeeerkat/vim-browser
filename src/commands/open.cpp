#include <unistd.h>
#include "commands/open.hpp"
#include "model/tab.hpp"
#include "widgets/page.hpp"
#include "widgets/tabs.hpp"
#include "helpers.hpp"


namespace Commands {
    void on_page_loaded(uint8_t *tab_index);

    void open_exec(int argc, char **argv)
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
                    break;
            }
        }
        if (optind >= argc)
            return;

        std::string url(argv[optind]);
        Helpers::fix_url(&url);

        if (new_tab)
            open_in_new_tab(url);
        else
            open_in_current_tab(url);
    }



    void open_in_current_tab(std::string url)
    {
        uint8_t current_tab_index = TabsWidget::get_current_tab_index();
        Tab *current_tab = TabsWidget::get_displayed_tab();
        current_tab->load(url, (void (*) (void*)) on_page_loaded, &current_tab_index);
        TabsWidget::update_view();
    }
    void open_in_new_tab(std::string url)
    {
        Tab *new_tab = new Tab();
        int8_t new_tab_index = TabsWidget::add_tab(new_tab);
        if (new_tab_index < 0) {
            delete new_tab;
            return;
        }
        new_tab->load(url, (void (*) (void*)) on_page_loaded, &new_tab_index);
        TabsWidget::set_current_tab_index(new_tab_index);
        //TabsWidget::update_view();
    }

    void on_page_loaded(uint8_t *tab_index)
    {
        PageWidget::display(TabsWidget::get_tab(*tab_index)->get_document());
        // Updating tabs because the page's title is now set
        TabsWidget::update_view();
    }
}
