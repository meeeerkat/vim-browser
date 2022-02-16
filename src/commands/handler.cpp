#include <string>
#include "app.hpp"
#include "commands/handler.hpp"

namespace Commands {

Handler::Handler(App *_app)
    : Vim::Commands::Handler(_app), app(_app)
{}

Handler::~Handler() {}

int Handler::_exec_command(const std::string &command_name, int argc, char **argv, std::string *error_message) const
{
    int err_code = Vim::Commands::Handler::_exec_command(command_name, argc, argv, error_message);
    if (err_code <= 0) // vim command executed or error thrown
        return err_code;

    // vim command not found (err_code == 1)
    if (COMMANDS.count(command_name) == 0)
        return 1; // specific command not found

    return COMMANDS.at(command_name)(app, argc, argv, error_message);
}

}
