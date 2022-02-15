#ifndef __COMMANDS_HANDLER_HPP__
#define __COMMANDS_HANDLER_HPP__

#include <string>
#include <map>
#include "commands/global.hpp"

class App;

namespace Commands {

    #define DECLARE_COMMAND(NAME) int NAME ## _exec(App*, int, char**, std::string*);
    DECLARE_COMMAND(quit)
    DECLARE_COMMAND(open)
    DECLARE_COMMAND(history)
    DECLARE_COMMAND(close)
    DECLARE_COMMAND(tab_move)
    DECLARE_COMMAND(tab_next)
    DECLARE_COMMAND(tab_prev)
    DECLARE_COMMAND(write_command)
    DECLARE_COMMAND(scroll)
    DECLARE_COMMAND(interact)


    class Handler {
        public:
            Handler();
            ~Handler();
            int exec(App *app, const std::string &command) const;

        private:
            void print_message(App *app, const std::string&) const;
            #define COMMAND(NAME)  { #NAME, NAME ## _exec }
            std::map<std::string, int (*) (App*, int, char**, std::string*)> COMMANDS = 
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

            void set_global_variables(App *app, char **argv, int argc) const;
            std::map<std::string, const std::string& (*) (App*)> global_vars_getters = 
            {
                { "$CURRENT_URL", Global::get_current_url },
            };
    };

 }

#endif
