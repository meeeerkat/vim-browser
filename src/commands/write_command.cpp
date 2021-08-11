#include "commands/write_command.hpp"
#include "widgets/command.hpp"
#include "controller.hpp"


namespace Commands {
    int write_command_exec(int argc, char **argv, std::string *)
    {
        if (argc == 2) {
            const std::string base_command(argv[1]);
            Controller::command_widget->handle_input(&base_command);
        }
        else
            Controller::command_widget->handle_input(NULL);

        return 0;
    }
}
