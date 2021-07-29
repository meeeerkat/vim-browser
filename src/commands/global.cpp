#include "commands/global.hpp"
#include "controller.hpp"
#include "widgets/page.hpp"
#include "model/document.hpp"

namespace Commands::Global {
    const std::string &get_current_url()
    {
        return Controller::page_widget->get_displayed_document()->get_url();
    }
}

