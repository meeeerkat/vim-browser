#ifndef __INPUT_HANDLER_HPP__
#define __INPUT_HANDLER_HPP__

#include <ncurses.h>

// Only handles shortcuts (in the normal mode)
// Command writing or page form filling input is
// taken care of in the widgets themselves
namespace InputHandler {
    void init();
    void free();
    uint16_t get_char();
    void wait_and_read();
};

#endif
