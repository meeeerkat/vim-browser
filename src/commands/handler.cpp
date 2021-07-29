#include <ncurses.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <glib.h>
#include <unistd.h>
#include "commands/handler.hpp"
#include "commands/quit.hpp"
#include "commands/open.hpp"
#include "commands/history.hpp"
#include "commands/close.hpp"
#include "commands/tab.hpp"
#include "commands/write_command.hpp"
#include "commands/scroll.hpp"
#include "commands/interact.hpp"


namespace Commands {

Handler::Handler(void (*print_message_callback_p) (const std::string&))
{
    print_message_callback = print_message_callback_p;
}

Handler::~Handler()
{

}

int Handler::exec(const std::string &command) const
{
    int argc;
    char **argv;
    GError *error = NULL;

    if (!g_shell_parse_argv (command.c_str(), &argc, &argv, &error)) {
        std::string error_message(error->message);
        print_message_callback(error_message);
        g_clear_error(&error);
        return -1;
    }

    set_global_variables(argv, argc);
    const std::string command_name(argv[0]);
    if (command_name[0] == '!') {
        // Shell command
        std::string modified_command;
        for (int i=0; i < argc; i++) {
            modified_command += argv[i];
            modified_command += " ";
        }
        system(modified_command.c_str() + 1);
        g_strfreev(argv);
        return 0;
    }

    if (COMMANDS.count(command_name) == 0) {
        print_message_callback("Unknown command.");
        g_strfreev(argv);
        return -1;
    }

    std::string error_message;
    if (COMMANDS.at(command_name)(argc, argv, &error_message) < 0) {
        print_message_callback(error_message);
        g_strfreev(argv);
        return -2;
    }

    g_strfreev(argv);
    return 0;
}

void Handler::set_global_variables(char **argv, int argc) const
{
    for (int i=0; i < argc; i++) {
        std::string arg(argv[i]);
        if (global_vars_getters.count(arg) > 0) {
            const std::string replacement = global_vars_getters.at(arg)();
            free(argv[i]);
            argv[i] = strdup(replacement.c_str());
        }
    }
}

}
