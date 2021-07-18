#include "commands/interact.hpp"
#include "model/nodes/element.hpp"
#include "widgets/page.hpp"

namespace Commands {
    int interact_exec(int argc, char **argv, std::string *error_message)
    {
        Nodes::InteractiveElement *el = PageWidget::choose_interactive_element();
    }
}

