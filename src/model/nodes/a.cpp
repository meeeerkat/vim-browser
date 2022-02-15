#include "model/nodes/a.hpp"
#include "model/nodes/loader.hpp"
#include "commands/open.hpp"
#include "helpers/url.hpp"
#include "app.hpp"

namespace Nodes {
    A::A(const GumboElement *el, BuildData &build_data)
        : InteractiveElement(el, build_data)
    {
        base_url = build_data.base_url;
        href = load_attribute(el, "href");

        if (!href.empty())
            Helpers::Url::fix(href, base_url);
    }

    void A::printw(WINDOW *window, PrintingOptions &printing_options)
    {
        InteractiveElement::printw(window, printing_options);
        
        wattron(window, A_UNDERLINE);
        InteractiveElement::print_children(window, printing_options);
        wattroff(window, A_UNDERLINE);

        InteractiveElement::print_id(window, printing_options);
    }
    
    void A::interact(App *app, PrintingOptions::InteractionType type)
    {
        if (href.empty())
            return;

        Helpers::HttpRequest request{href};

        switch (type) {
            case PrintingOptions::InteractionType::CurrentTab:
                Commands::open_in_current_tab(app, request);
                break;
            case PrintingOptions::InteractionType::NewTab:
                Commands::open_in_new_tab(app, request);
                break;
            default:
                break;
        }
    }

}
