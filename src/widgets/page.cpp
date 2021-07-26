#include <ncurses.h>
#include <ctype.h>
#include "widgets/page.hpp"
#include "model/document.hpp"

namespace Widgets {

Page::Page()
{
    pad = newpad(MAX_LINES_NB, COLS);
    keypad(pad, TRUE);

    displayed_document = NULL;
}

Page::~Page()
{
    delwin(pad);
}

void Page::display(Document *doc, uint32_t start_line_p)
{
    displayed_document = doc;

    // Printing doc
    start_line = start_line_p;
    refresh_display();
}

Document *Page::get_displayed_document()
{
    return displayed_document;
}

void Page::scroll_to(uint32_t start_line_p)
{
    if (start_line_p > MAX_LINES_NB)
        return;

    start_line = start_line_p;
    prefresh(pad, start_line, 0, 1, 0, LINES-2, COLS);
}

void Page::refresh_display()
{
    wclear(pad);
    displayed_document->printw(pad, printing_options);
    prefresh(pad, start_line, 0, 1, 0, LINES-2, COLS);
}

void Page::refresh_display(Nodes::PrintingOptions new_options)
{
    printing_options = new_options;
    refresh_display();
}

uint32_t Page::get_start_line() const
{
    return start_line;
}

int Page::interact(Nodes::PrintingOptions::InteractionType type, std::string *error_message)
{
    // Printing doc showing interactions
    printing_options = Nodes::PrintingOptions{type, ""};
    refresh_display();

    // Handling input to choose the element
    uint16_t c = wgetch(pad);
    while (isdigit(c)) {
        printing_options.interaction_current_id += c;
        refresh_display();
        c = wgetch(pad);
    }

    if (c == '\n' || c == KEY_ENTER) {
        Nodes::InteractiveElement *el = displayed_document->get_interactive_element(printing_options.interaction_current_id);
        if (el != NULL)
            el->interact(type);
        else {
            refresh_display(Nodes::PrintingOptions{});
            *error_message = "Id not found.";
            return -1;
        }
    }

    refresh_display(Nodes::PrintingOptions{});
    return 0;
}

}
