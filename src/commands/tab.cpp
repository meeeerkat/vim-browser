#include "commands/tab.hpp"
#include "widgets/tabs.hpp"
#include "widgets/page.hpp"

namespace Commands {
    int tab_move_exec(int argc, char **argv, std::string *error_message)
    {
        if (argc != 2) {
            *error_message = "Usage: tab_move index";
            return -1;
        }
        const uint8_t new_index = std::stoi(argv[1]);
        tab_move(new_index);
    }
    int tab_next_exec(int argc, char **argv, std::string *error_message)
    {
        tab_next();
        return 0;
    }
    int tab_prev_exec(int argc, char **argv, std::string *error_message)
    {
        tab_prev();
        return 0;
    }
    void tab_move(uint8_t new_index)
    {
        TabsWidget::set_current_tab_index(new_index);
        PageWidget::display(TabsWidget::get_current_document());
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
