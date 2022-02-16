#include <ncurses.h>
#include "commands/close.hpp"
#include "widgets/tabs.hpp"
#include "widgets/page.hpp"
#include "app.hpp"

namespace Commands {
    int close_exec(App *app, int, char **, std::string *error_message)
    {
        const int err_code = app->get_tabs_widget()->close_current_tab();
        if (err_code < 0)
            *error_message = "Cannot close this tab.";

        if (app->get_page_widget()->get_displayed_document() != app->get_tabs_widget()->get_current_document())
            app->get_page_widget()->display(app->get_tabs_widget()->get_current_document());

        return err_code;
    }
}
