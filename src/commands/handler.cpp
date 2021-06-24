#include <ncurses.h>
#include <stdio.h>
#include <string>
#include <glib.h>
#include "commands/handler.hpp"
#include "helpers.hpp"
#include "commands/quit.hpp"
#include "commands/open.hpp"
#include "commands/history.hpp"
#include "commands/close.hpp"


namespace CommandsHandler {

    // Private static const structures (Here so there is no need to include all commands into the .hpp)
    typedef struct command {
        std::string name;
        void (*exec) (int, char**);
    } command_t;


    namespace {
        void (*print_message_callback) (std::string);
        const uint16_t COMMANDS_NB = 4;
        #define COMMAND(NAME)  { #NAME, Commands::NAME ## _exec }
        #define doublecolon ::
        const command_t COMMANDS[] = 
        {
            COMMAND(quit),
            COMMAND(open),
            COMMAND(history),
            COMMAND(close),
        };
    }


    void init(void (*print_message_callback_p) (std::string))
    {
        print_message_callback = print_message_callback_p;
    }

    void free()
    {

    }

    int exec(std::string command)
    {
        int argc;
        char **argv;
        GError *error = NULL;

        if (!g_shell_parse_argv (command.c_str(), &argc, &argv, &error)) {
            std::string error_message(error->message);
            print_message_callback(error_message);
            g_clear_error(&error);
            g_strfreev(argv);
            return -1;
        }

        uint16_t i = 0;
        while (i < COMMANDS_NB && COMMANDS[i].name != argv[0])
            i++;

        if (i < COMMANDS_NB)
            COMMANDS[i].exec(argc, argv);
        else {
            print_message_callback("Unknown command.");
            g_strfreev(argv);
            return -1;
        }

        g_strfreev(argv);
        return 0;
    }
}
