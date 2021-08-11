#include "widgets/tabs.hpp"
#include <vector>

namespace Widgets {

Tabs::Tabs()
    : Widget()
{
    // Takes only the first line
    window = newwin(1, COLS, 0, 0);
    current_tab_index = -1;
}

Tabs::~Tabs()
{
    for (size_t i=0; i < docs.size(); i++)
        delete docs[i];
    delwin(window);
}

Document *Tabs::get_document(uint8_t tab_index)
{
    return docs[tab_index];
}

Document *Tabs::get_current_document()
{
    return get_document(current_tab_index);
}

int8_t Tabs::add_tab(Document *new_doc, uint8_t tab_index)
{
    if (!can_add_tab() || tab_index > get_tabs_nb())
        return -1;

    if (tab_index == get_tabs_nb())
        docs.push_back(new_doc);
    else
        docs.insert(docs.begin() + tab_index, new_doc);

    if (current_tab_index < 0)
        current_tab_index = 0;

    refresh_display();
    return get_tabs_nb()-1;
}
bool Tabs::can_add_tab() const
{
    return get_tabs_nb() < TABS_MAX_NB;
}

void Tabs::replace_document(Document *new_doc, uint8_t tab_index)
{
    if (tab_index >= get_tabs_nb())
        return;
    delete docs[tab_index];
    docs[tab_index] = new_doc;
    refresh_display();
}

int8_t Tabs::set_current_tab_index(uint8_t new_tab_index)
{
    if (new_tab_index >= get_tabs_nb())
        return -1;
    if (new_tab_index == current_tab_index)
        return 0;

    current_tab_index = (int8_t) new_tab_index;
    refresh_display();

    return 0;
}
int8_t Tabs::get_current_tab_index() const
{
    return current_tab_index;
}
uint8_t Tabs::get_tabs_nb() const
{
    return (uint8_t) docs.size();
}

void Tabs::refresh_display() const
{
    if (!can_refresh())
        return;

    wclear(window);

    const uint16_t tab_size = COLS/get_tabs_nb();
    for (uint8_t i=0; i < get_tabs_nb(); i++) {
        const bool is_current_tab = get_current_tab_index() == i;
        if (is_current_tab)
            wattron(window, A_BOLD);
        mvwprintw(window, 0, i*tab_size, "%hhu: %s", i, docs[i]->get_title().c_str());
        if (is_current_tab)
            wattroff(window, A_BOLD);
    }

    wrefresh(window);
}

int Tabs::close_current_tab()
{
    return close_tab(current_tab_index);
}

int Tabs::close_tab(uint8_t tab_index)
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
    
    refresh_display();
    return 0;
}

}
