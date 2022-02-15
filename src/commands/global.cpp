#include "commands/global.hpp"
#include "app.hpp"
#include "widgets/page.hpp"
#include "model/document.hpp"

namespace Commands::Global {
    const std::string &get_current_url(App *app)
    {
        return app->getPageWidget()->get_displayed_document()->get_request().url;
    }
}

