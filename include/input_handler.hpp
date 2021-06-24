#ifndef __INPUT_HANDLER_HPP__
#define __INPUT_HANDLER_HPP__

#include <ncurses.h>

namespace InputHandler {
    void init();
    void free();
    void wait_and_read();
};

#endif
