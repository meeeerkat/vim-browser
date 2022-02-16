#include "commands/tab.hpp"
#include "widgets/tabs.hpp"
#include "widgets/page.hpp"
#include "app.hpp"

namespace Commands {
    int tab_move_exec(App *app, int argc, char **argv, std::string *error_message)
    {
        if (argc != 2) {
            *error_message = "Usage: tab_move index";
            return -1;
        }
        const uint8_t new_index = std::stoi(argv[1]);
        tab_move(app, new_index);
        return 0;
    }
    int tab_next_exec(App *app, int argc, char **, std::string *)
    {
        tab_next(app);
        return 0;
    }
    int tab_prev_exec(App *app, int argc, char **, std::string *)
    {
        tab_prev(app);
        return 0;
    }
    void tab_move(App *app, uint8_t new_index)
    {
        app->get_tabs_widget()->set_current_tab_index(new_index);
        app->get_page_widget()->display(app->get_tabs_widget()->get_current_document());
    }
    void tab_prev(App *app)
    {
        uint8_t current_tab_index = app->get_tabs_widget()->get_current_tab_index();
        if (current_tab_index != 0)
            tab_move(app, app->get_tabs_widget()->get_current_tab_index() - 1);
        else
            tab_move(app, app->get_tabs_widget()->get_tabs_nb() - 1);
    }
    void tab_next(App *app)
    {
        uint8_t current_tab_index = app->get_tabs_widget()->get_current_tab_index();
        if (current_tab_index != app->get_tabs_widget()->get_tabs_nb() - 1)
            tab_move(app, app->get_tabs_widget()->get_current_tab_index() + 1);
        else
            tab_move(app, 0);
    }
}
