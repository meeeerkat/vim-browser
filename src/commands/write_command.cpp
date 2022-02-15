#include "commands/write_command.hpp"
#include "widgets/command.hpp"
#include "app.hpp"


namespace Commands {
    int write_command_exec(App *app, int argc, char **argv, std::string *)
    {
        if (argc == 2) {
            const std::string base_command(argv[1]);
            app->getCommandWidget()->handle_input(app, &base_command);
        }
        else
            app->getCommandWidget()->handle_input(app, NULL);

        return 0;
    }
}
