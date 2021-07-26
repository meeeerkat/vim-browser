#include "commands/interact.hpp"
#include "model/nodes/element.hpp"
#include "widgets/page.hpp"
#include "controller.hpp"

namespace Commands {
    int interact_exec(int argc, char **argv, std::string *error_message)
    {
        uint8_t type = 0;
        if (argc > 1)
            type = stoi(std::string(argv[1]));

        return Controller::page_widget->interact(static_cast<Nodes::PrintingOptions::InteractionType>(type), error_message);
    }
}

