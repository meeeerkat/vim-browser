#ifndef __INPUT_HANDLER_HPP__
#define __INPUT_HANDLER_HPP__

#include <ncurses.h>
#include <string>

namespace Config { class Shortcuts; }

// Only handles shortcuts (in the normal mode)
// Command writing or page form filling input is
// taken care of in the widgets themselves
class InputHandler {
    public:
        InputHandler();
        ~InputHandler();
        uint16_t get_char();
        void wait_and_read(int (*exec) (const std::string&));

    private:
        WINDOW *fake_window;
};

#endif
