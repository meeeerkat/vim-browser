#include <boost/algorithm/string.hpp>
#include "model/nodes/text.hpp"


namespace Nodes {
    Text::Text(const GumboText *gumbo_text)
    {
        text = std::string(gumbo_text->text);
        boost::trim(text);
    }

    Text::~Text()
    {

    }

    void Text::printw(WINDOW *window) const
    {
        wprintw(window, "%s ", text.c_str());
    }
}
