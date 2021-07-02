#include <ncurses.h>
#include "commands/close.hpp"
#include "widgets/tabs.hpp"
#include "widgets/page.hpp"

namespace Commands {
    int close_exec(int argc, char **argv, std::string *error_message)
    {
        const int err_code = TabsWidget::close_current_tab();
        if (err_code < 0)
            *error_message = "Cannot close this tab";

        if (PageWidget::get_displayed_document() != TabsWidget::get_displayed_document())
            PageWidget::display(TabsWidget::get_displayed_document());

        return err_code;
    }
}
