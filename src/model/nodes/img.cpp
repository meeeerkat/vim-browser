#include "model/nodes/img.hpp"
#include <stdlib.h>
#include "model/nodes/loader.hpp"
#include "helpers/url.hpp"


namespace Nodes {
    Img::Img(const GumboElement *el, BuildData &build_data)
        : InteractiveElement(el, build_data)
    {
        alt = load_attribute(el, "alt");
        src = load_attribute(el, "src");
        Helpers::Url::fix(src);
    }

    void Img::printw(WINDOW *window, PrintingOptions &printing_options) const
    {
        if (alt.empty())
            wprintw(window, "%s ", src.c_str());
        else
            wprintw(window, "%s ", alt.c_str());

        if (printing_options.interaction_type == PrintingOptions::InteractionType::Content)
            InteractiveElement::printw(window, printing_options);
    }
    
    void Img::interact(PrintingOptions::InteractionType type)
    {
        if (type != PrintingOptions::InteractionType::Content)
            return;

        std::string command = "display " + src;
        system(command.c_str());
    }
}
