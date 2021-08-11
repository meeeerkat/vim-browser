#include <boost/algorithm/string.hpp>
#include "model/nodes/text.hpp"


namespace Nodes {
    Text::Text(const GumboText *gumbo_text, BuildData &build_data)
        : Node(build_data)
    {
        text = std::string(gumbo_text->text);
        boost::trim(text);
    }

    Text::~Text()
    {

    }

    void Text::printw(WINDOW *window, PrintingOptions &)
    {
        wprintw(window, "%s ", text.c_str());
    }
}
