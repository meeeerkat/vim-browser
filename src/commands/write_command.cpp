#include "commands/write_command.hpp"
#include "widgets/command.hpp"


namespace Commands {
    int write_command_exec(int argc, char **argv, std::string *error_message)
    {
        if (argc == 2) {
            const std::string base_command(argv[1]);
            CommandWidget::handle_input(&base_command);
        }
        else
            CommandWidget::handle_input(NULL);
    }
}
