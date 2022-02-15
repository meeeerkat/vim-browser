#include "commands/interact.hpp"
#include "model/nodes/element.hpp"
#include "widgets/page.hpp"
#include "app.hpp"

namespace Commands {
    int interact_exec(App *app, int argc, char **argv, std::string *error_message)
    {
        uint8_t type_int = 0;
        if (argc > 1)
            type_int = stoi(std::string(argv[1]));

        Nodes::PrintingOptions::InteractionType type = static_cast<Nodes::PrintingOptions::InteractionType>(type_int);
        if (type != Nodes::PrintingOptions::InteractionType::None)
            return app->getPageWidget()->interact(app, type, error_message);

        return 0;
    }
}

