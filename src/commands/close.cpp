#include <ncurses.h>
#include "commands/close.hpp"
#include "widgets/tabs.hpp"

namespace Commands {
    int close_exec(int argc, char **argv, std::string *error_message)
    {
        const int err_code = TabsWidget::close_current_tab();
        if (err_code < 0)
            *error_message = "Cannot close this tab";

        return err_code;
    }
}
