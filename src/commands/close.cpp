#include <ncurses.h>
#include "commands/close.hpp"
#include "widgets/tabs.hpp"

namespace Commands {
    void close_exec(int argc, char **argv)
    {
        TabsWidget::close_current_tab();
    }
}
