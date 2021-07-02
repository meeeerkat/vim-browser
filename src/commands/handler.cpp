#include <ncurses.h>
#include <stdio.h>
#include <string>
#include <glib.h>
#include <unistd.h>
#include "commands/handler.hpp"
#include "commands/quit.hpp"
#include "commands/open.hpp"
#include "commands/history.hpp"
#include "commands/close.hpp"
#include "commands/tab.hpp"
#include "commands/write_command.hpp"


namespace CommandsHandler {

    // Private static const structures (Here so there is no need to include all commands into the .hpp)
    typedef struct command {
        std::string name;
        int (*exec) (int, char**, std::string*);
    } command_t;


    namespace {
        void (*print_message_callback) (std::string);
        const uint16_t COMMANDS_NB = 8;
        #define COMMAND(NAME)  { #NAME, Commands::NAME ## _exec }
        const command_t COMMANDS[] = 
        {
            COMMAND(quit),
            COMMAND(open),
            COMMAND(history),
            COMMAND(close),
            COMMAND(tab_move),
            COMMAND(tab_next),
            COMMAND(tab_prev),
            COMMAND(write_command),
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

        uint16_t i = 0;
        while (i < COMMANDS_NB && COMMANDS[i].name != argv[0])
            i++;

        if (i >= COMMANDS_NB) {
            print_message_callback("Unknown command.");
            g_strfreev(argv);
            return -1;
        }

        std::string error_message;
        if (COMMANDS[i].exec(argc, argv, &error_message) < 0) {
            print_message_callback(error_message);
            g_strfreev(argv);
            return -2;
        }

        g_strfreev(argv);
        return 0;
    }
}
