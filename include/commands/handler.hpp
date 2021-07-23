#ifndef __COMMANDS_HANDLER_HPP__
#define __COMMANDS_HANDLER_HPP__

#include <string>


namespace CommandsHandler {
    void init(void (*print_message_callback) (const std::string&));
    void free();
    int exec(const std::string &command);
 };

#endif
