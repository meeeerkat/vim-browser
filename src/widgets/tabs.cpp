#include "widgets/tabs.hpp"
#include <vector>

namespace TabsWidget {
    namespace {
        WINDOW *window;
        // Pointers to control their life cycle (or they get destroyed right away)
        std::vector<Page*> pages;
        uint8_t current_tab_index;
        void (*update_page_display_callback) (Page*);
    }

    void init(void (*update_page_display_callback_p) (Page*))
    {
        // Takes only the first line
        window = newwin(1, COLS, 0, 0);
        current_tab_index = 0;
        update_page_display_callback = update_page_display_callback_p;
    }
    void free()
    {
        for (size_t i=0; i < pages.size(); i++)
            free(pages[i]);
        delwin(window);
    }

    Page *get_tab_page(uint8_t tab_index)
    {
        return pages[tab_index];
    }

    Page *get_displayed_page()
    {
        return get_tab_page(current_tab_index);
    }

    int8_t add_tab(Page *new_page)
    {
        if (get_pages_nb() == TABS_MAX_NB)
            return -1;

        pages.push_back(new_page);
        update_view();
        return get_pages_nb()-1;
    }
    int8_t set_current_tab_index(uint8_t new_tab_index)
    {
        if (new_tab_index >= get_pages_nb())
            return -1;
        if (new_tab_index == current_tab_index)
            return 0;

        current_tab_index = new_tab_index;
        update_view();
        update_page_display_callback(pages[current_tab_index]);

        return 0;
    }
    uint8_t get_current_tab_index()
    {
        return current_tab_index;
    }
    uint8_t get_pages_nb()
    {
        return (uint8_t) pages.size();
    }

    void update_view()
    {
        wclear(window);

        const uint16_t tab_size = COLS/get_pages_nb();
        for (uint32_t i=0; i < get_pages_nb(); i++) {
            char *title = pages[i]->get_title();
            if (title == NULL)
                mvwprintw(window, 0, i*tab_size, "%hhu: %s", i, pages[i]->get_url()->c_str());
            else
                mvwprintw(window, 0, i*tab_size, "%hhu: %s", i, title);
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
        if (get_pages_nb() == 1 || get_pages_nb() <= tab_index)
            return;

        pages.erase(pages.begin() + tab_index);

        // Not changing the current tab's page if it's not the one deleted
        if (current_tab_index > tab_index)
            current_tab_index--;
        // If it's the one deleted, the next one is displayed except if it's the last one
        else if(current_tab_index == tab_index) {
            if (current_tab_index == get_pages_nb())
                current_tab_index--;
            update_page_display_callback(pages[current_tab_index]);
        }
        
        update_view();
    }
}
