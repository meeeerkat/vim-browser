#include "widgets/tabs.hpp"
#include <vector>

namespace TabsWidget {
    namespace {
        WINDOW *window;
        // Pointers to control their life cycle (or they get destroyed right away)
        std::vector<Document*> docs;
        int8_t current_tab_index;
    }

    void init()
    {
        // Takes only the first line
        window = newwin(1, COLS, 0, 0);
        current_tab_index = -1;
    }
    void free()
    {
        for (size_t i=0; i < docs.size(); i++)
            free(docs[i]);
        delwin(window);
    }

    Document *get_document(uint8_t tab_index)
    {
        return docs[tab_index];
    }

    Document *get_current_document()
    {
        return get_document(current_tab_index);
    }

    int8_t add_tab(Document *new_doc, uint8_t tab_index)
    {
        if (!can_add_tab() || tab_index > get_tabs_nb())
            return -1;

        if (tab_index == get_tabs_nb())
            docs.push_back(new_doc);
        else
            docs.insert(docs.begin() + tab_index, new_doc);

        if (current_tab_index < 0)
            current_tab_index = 0;

        update_view();
        return get_tabs_nb()-1;
    }
    bool can_add_tab()
    {
        return get_tabs_nb() < TABS_MAX_NB;
    }

    void replace_document(Document *new_doc, uint8_t tab_index)
    {
        if (tab_index >= get_tabs_nb())
            return;
        delete docs[tab_index];
        docs[tab_index] = new_doc;
        update_view();
    }

    int8_t set_current_tab_index(uint8_t new_tab_index)
    {
        if (new_tab_index >= get_tabs_nb())
            return -1;
        if (new_tab_index == current_tab_index)
            return 0;

        current_tab_index = (int8_t) new_tab_index;
        update_view();

        return 0;
    }
    int8_t get_current_tab_index()
    {
        return current_tab_index;
    }
    uint8_t get_tabs_nb()
    {
        return (uint8_t) docs.size();
    }

    void update_view()
    {
        wclear(window);

        const uint16_t tab_size = COLS/get_tabs_nb();
        for (uint32_t i=0; i < get_tabs_nb(); i++) {
            const bool is_current_tab = get_current_tab_index() == i;
            if (is_current_tab)
                wattron(window, A_BOLD);
            mvwprintw(window, 0, i*tab_size, "%hhu: %s", i, docs[i]->get_title()->c_str());
            if (is_current_tab)
                wattroff(window, A_BOLD);
        }

        wrefresh(window);
    }

    int close_current_tab()
    {
        return close_tab(current_tab_index);
    }

    int close_tab(uint8_t tab_index)
    {
        // Always keep one tab opened
        if (get_tabs_nb() == 1 || get_tabs_nb() <= tab_index)
            return -1;

        docs.erase(docs.begin() + tab_index);

        // Not changing the current tab's tab if it's not the one deleted
        if (current_tab_index > tab_index)
            current_tab_index--;
        // If it's the one deleted, the next one is displayed except if it's the last one
        else if(current_tab_index == tab_index) {
            if (current_tab_index == get_tabs_nb())
                current_tab_index--;
        }
        
        update_view();
        return 0;
    }
}
