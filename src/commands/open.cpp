#include <unistd.h>
#include <iostream>
#include "commands/open.hpp"
#include "widgets/page.hpp"
#include "widgets/tabs.hpp"
#include "helpers/url.hpp"
#include "helpers/callback.hpp"


namespace Commands {
    void on_doc_loaded(void *tab_index);

    int open_exec(int argc, char **argv, std::string *error_message)
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
        if (optind >= argc) {
            *error_message = "Usage: open [-t] URL";
            return -1;
        }

        std::string url(argv[optind]);
        Helpers::Url::fix(url);

        if (new_tab)
            open_in_new_tab(url);
        else
            open_in_current_tab(url);

        return 0;
    }



    void open_in_current_tab(std::string url)
    {
        // Current_tab_index is supposed to be deleted in on_doc_loaded
        uint8_t *current_tab_index = new uint8_t(TabsWidget::get_current_tab_index());
        Document *new_doc = new Document(url, new Helpers::Callback(on_doc_loaded, current_tab_index));
        TabsWidget::replace_document(new_doc, *current_tab_index);
        PageWidget::display(new_doc);
    }
    void open_in_new_tab(std::string url)
    {
        if (!TabsWidget::can_add_tab())
            return;

        uint8_t *next_tab_index = new uint8_t(TabsWidget::get_current_tab_index() + 1);
        Document *new_doc = new Document(url, new Helpers::Callback(on_doc_loaded, next_tab_index));
        TabsWidget::add_tab(new_doc, *next_tab_index);
        TabsWidget::set_current_tab_index(*next_tab_index);
        PageWidget::display(new_doc);
    }

    void on_doc_loaded(void *arg)
    {
        uint8_t *tab_index = (uint8_t*) arg;
        // Updating tabs because the page's title is now set
        TabsWidget::update_view();

        // Displaying it
        if (*tab_index == TabsWidget::get_current_tab_index())
            PageWidget::display(TabsWidget::get_document(*tab_index));

        delete tab_index;
    }
}
