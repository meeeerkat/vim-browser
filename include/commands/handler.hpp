#ifndef __COMMANDS_HANDLER_HPP__
#define __COMMANDS_HANDLER_HPP__

#include <string>
#include <map>
#include "vim/commands/handler.hpp"

class App;

namespace Commands {

    typedef int (*Command) (App*, int, char**, std::string*);

    #define DECLARE_COMMAND(NAME) int NAME ## _exec(App*, int, char**, std::string*);
    DECLARE_COMMAND(open)
    DECLARE_COMMAND(history)
    DECLARE_COMMAND(close)
    DECLARE_COMMAND(tab_move)
    DECLARE_COMMAND(tab_next)
    DECLARE_COMMAND(tab_prev)
    DECLARE_COMMAND(scroll)
    DECLARE_COMMAND(interact)


    class Handler : public Vim::Commands::Handler {
        public:
            Handler(App *app);
            virtual ~Handler();
            int exec(const std::string &command) const;

        protected:
            virtual int _exec_command(const std::string &command_name, int argc, char **argv, std::string *error_message) const;

        private:
            App *app;

            #define COMMAND(NAME)  { #NAME, NAME ## _exec }
            std::map<std::string, Command> COMMANDS = 
            {
                COMMAND(open),
                COMMAND(history),
                COMMAND(close),
                COMMAND(tab_move),
                COMMAND(tab_next),
                COMMAND(tab_prev),
                COMMAND(scroll),
                COMMAND(interact),
            };
    };

}

#endif
