#include <ncurses.h>
#include "commands/close.hpp"
#include "widgets/tabs.hpp"
#include "widgets/page.hpp"
#include "controller.hpp"

namespace Commands {
    int close_exec(int, char **, std::string *error_message)
    {
        const int err_code = Controller::tabs_widget->close_current_tab();
        if (err_code < 0)
            *error_message = "Cannot close this tab.";

        if (Controller::page_widget->get_displayed_document() != Controller::tabs_widget->get_current_document())
            Controller::page_widget->display(Controller::tabs_widget->get_current_document());

        return err_code;
    }
}
