#include "model/nodes/a.hpp"
#include "model/nodes/loader.hpp"
#include "commands/open.hpp"
#include "helpers/url.hpp"

namespace Nodes {
    A::A(const GumboElement *el, BuildData *build_data)
        : InteractiveElement(el, build_data)
    {
        base_url = build_data->base_url;
        href = load_attribute(el, "href");

        if (!href.empty())
            Helpers::Url::fix(&href, base_url);
    }

    void A::printw(WINDOW *window, PrintingOptions *printing_options) const
    {
        wattron(window, A_UNDERLINE);
        Element::printw(window, printing_options);
        wattroff(window, A_UNDERLINE);

        InteractiveElement::printw(window, printing_options);
    }
    
    void A::interact(uint8_t type)
    {
        if (href.empty())
            return;

        if (type == 0)
            Commands::open_in_current_tab(href);
        else
            Commands::open_in_new_tab(href);
    }
}
