#include <ncurses.h>
#include <stdio.h>
#include <string>
#include <map>
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


namespace CommandsHandler {

    namespace {
        void (*print_message_callback) (std::string);
        #define COMMAND(NAME)  { #NAME, Commands::NAME ## _exec }
        std::map<std::string, int (*) (int, char**, std::string*)> COMMANDS = 
        {
            COMMAND(quit),
            COMMAND(open),
            COMMAND(history),
            COMMAND(close),
            COMMAND(tab_move),
            COMMAND(tab_next),
            COMMAND(tab_prev),
            COMMAND(write_command),
            COMMAND(scroll),
            COMMAND(interact),
        };
    }


    void init(void (*print_message_callback_p) (std::string))
    {
        print_message_callback = print_message_callback_p;
    }

    void free()
    {

    }

    int exec(const std::string *command)
    {
        int argc;
        char **argv;
        GError *error = NULL;

        if (!g_shell_parse_argv (command->c_str(), &argc, &argv, &error)) {
            std::string error_message(error->message);
            print_message_callback(error_message);
            g_clear_error(&error);
            return -1;
        }

        const std::string command_name(argv[0]);
        if (COMMANDS.count(command_name) == 0) {
            print_message_callback("Unknown command.");
            g_strfreev(argv);
            return -1;
        }

        std::string error_message;
        if (COMMANDS[command_name](argc, argv, &error_message) < 0) {
            print_message_callback(error_message);
            g_strfreev(argv);
            return -2;
        }

        g_strfreev(argv);
        return 0;
    }
}
