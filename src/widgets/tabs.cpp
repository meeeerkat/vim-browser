#include "widgets/tabs.hpp"
#include <vector>

namespace TabsWidget {
    namespace {
        WINDOW *window;
        // Pointers to control their life cycle (or they get destroyed right away)
        std::vector<Tab*> tabs;
        uint8_t current_tab_index;
        void (*display_document_callback) (Document*);
    }

    void init(void (*display_document_callback_p) (Document*))
    {
        // Takes only the first line
        window = newwin(1, COLS, 0, 0);
        current_tab_index = -1;
        display_document_callback = display_document_callback_p;
    }
    void free()
    {
        for (size_t i=0; i < tabs.size(); i++)
            free(tabs[i]);
        delwin(window);
    }

    Tab *get_tab(uint8_t tab_index)
    {
        return tabs[tab_index];
    }

    Tab *get_displayed_tab()
    {
        return get_tab(current_tab_index);
    }

    int8_t add_tab(Tab *new_tab)
    {
        if (!can_add_tab())
            return -1;

        tabs.push_back(new_tab);
        update_view();
        return get_tabs_nb()-1;
    }
    bool can_add_tab()
    {
        return get_tabs_nb() < TABS_MAX_NB;
    }

    int8_t set_current_tab_index(uint8_t new_tab_index)
    {
        if (new_tab_index >= get_tabs_nb())
            return -1;
        if (new_tab_index == current_tab_index)
            return 0;

        current_tab_index = new_tab_index;
        update_view();
        display_document_callback(tabs[current_tab_index]->get_document());

        return 0;
    }
    uint8_t get_current_tab_index()
    {
        return current_tab_index;
    }
    uint8_t get_tabs_nb()
    {
        return (uint8_t) tabs.size();
    }

    void update_view()
    {
        wclear(window);

        const uint16_t tab_size = COLS/get_tabs_nb();
        for (uint32_t i=0; i < get_tabs_nb(); i++) {
            Document *doc = tabs[i]->get_document();
            const char *title;
            if (doc)
                title = doc->get_title()->c_str();
            else
                title = tabs[i]->get_url()->c_str();
            const bool is_current_tab = get_current_tab_index() == i;
            if (is_current_tab)
                wattron(window, A_BOLD);
            mvwprintw(window, 0, i*tab_size, "%hhu: %s", i, title);
            if (is_current_tab)
                wattroff(window, A_BOLD);
        }

        wrefresh(window);
    }

    void close_current_tab()
    {
        close_tab(current_tab_index);
    }

    void close_tab(uint8_t tab_index)
    {
        // Always keep one tab opened
        if (get_tabs_nb() == 1 || get_tabs_nb() <= tab_index)
            return;

        tabs.erase(tabs.begin() + tab_index);

        // Not changing the current tab's tab if it's not the one deleted
        if (current_tab_index > tab_index)
            current_tab_index--;
        // If it's the one deleted, the next one is displayed except if it's the last one
        else if(current_tab_index == tab_index) {
            if (current_tab_index == get_tabs_nb())
                current_tab_index--;
            display_document_callback(tabs[current_tab_index]->get_document());
        }
        
        update_view();
    }
}
