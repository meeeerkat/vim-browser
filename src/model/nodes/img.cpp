#include "model/nodes/img.hpp"
#include <stdlib.h>
#include <regex>
#include "model/nodes/loader.hpp"
#include "helpers/url.hpp"
#include "config.hpp"
#include "app.hpp"


namespace Nodes {

    Img::Img(const GumboElement *el, BuildData &build_data)
        : InteractiveElement(el, build_data)
    {
        alt = load_attribute(el, "alt");
        src = load_attribute(el, "src");
        Helpers::Url::fix(src);
    }

    void Img::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        InteractiveElement::printw(window, printing_options);

        if (alt.empty())
            wprintw(window, "%s ", src.c_str());
        else
            wprintw(window, "%s ", alt.c_str());

        InteractiveElement::print_id(window, printing_options);
    }
    
    void Img::interact(App *app, PrintingOptions::InteractionType)
    {
        std::string command = std::regex_replace(app->get_config()->get_media_display_command(), std::regex("\\$URL"), src);
        system(command.c_str());
    }

}
