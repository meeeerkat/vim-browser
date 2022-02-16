#include <unistd.h>
#include <iostream>
#include <functional>
#include "commands/open.hpp"
#include "model/document_loader.hpp"
#include "widgets/page.hpp"
#include "widgets/tabs.hpp"
#include "helpers/url.hpp"
#include "config.hpp"
#include "app.hpp"


namespace Commands {

    int open_exec(App *app, int argc, char **argv, std::string *error_message)
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

        Helpers::HttpRequest request{argv[optind]};
        Helpers::Url::fix(request.url, app->get_config()->get_search_url());

        if (new_tab)
            open_in_new_tab(app, request);
        else
            open_in_current_tab(app, request);

        return 0;
    }


    void open(App *app, const Helpers::HttpRequest &request, bool in_new_tab)
    {
        if (in_new_tab)
            open_in_new_tab(app, request);
        else
            open_in_current_tab(app, request);
    }


    static void on_doc_loaded(App *app, uint8_t tab_index)
    {
        // Updating tabs because the page's title is now set
        app->get_tabs_widget()->refresh_display();

        // Displaying it
        if (tab_index == app->get_tabs_widget()->get_current_tab_index())
            app->get_page_widget()->display(app->get_tabs_widget()->get_document(tab_index));
    }

    void open_in_current_tab(App *app, const Helpers::HttpRequest &request)
    {
        // Current_tab_index is supposed to be deleted in on_doc_loaded
        const uint8_t current_tab_index = app->get_tabs_widget()->get_current_tab_index();
        Document *new_doc = new Document(request, std::bind(&on_doc_loaded, app, current_tab_index));
        app->get_document_loader()->load_async(new_doc);
        app->get_tabs_widget()->replace_document(new_doc, current_tab_index);
        app->get_page_widget()->display(new_doc);
    }

    void open_in_new_tab(App *app, const Helpers::HttpRequest &request)
    {
        if (!app->get_tabs_widget()->can_add_tab())
            return;

        const uint8_t next_tab_index = app->get_tabs_widget()->get_current_tab_index() + 1;
        Document *new_doc = new Document(request, std::bind(&on_doc_loaded, app, next_tab_index));
        app->get_document_loader()->load_async(new_doc);
        app->get_tabs_widget()->add_tab(new_doc, next_tab_index);
        app->get_tabs_widget()->set_current_tab_index(next_tab_index);
        app->get_page_widget()->display(new_doc);
    }
}
