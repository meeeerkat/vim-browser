#include "commands/tab.hpp"
#include "widgets/tabs.hpp"

namespace Commands {
    void tab_move_exec(int argc, char **argv)
    {
        if (argc != 2)
            return;
        const uint8_t new_index = std::stoi(argv[1]);
        tab_move(new_index);
    }
    void tab_next_exec(int argc, char **argv)
    {
        tab_next();
    }
    void tab_prev_exec(int argc, char **argv)
    {
        tab_prev();
    }
    void tab_move(uint8_t new_index)
    {
        TabsWidget::set_current_tab_index(new_index);
    }
    void tab_prev()
    {
        uint8_t current_tab_index = TabsWidget::get_current_tab_index();
        if (current_tab_index != 0)
            tab_move(TabsWidget::get_current_tab_index() - 1);
        else
            tab_move(TabsWidget::get_tabs_nb() - 1);
    }
    void tab_next()
    {
        uint8_t current_tab_index = TabsWidget::get_current_tab_index();
        if (current_tab_index != TabsWidget::get_tabs_nb() - 1)
            tab_move(TabsWidget::get_current_tab_index() + 1);
        else
            tab_move(0);
    }
}
