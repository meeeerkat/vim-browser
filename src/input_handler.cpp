#include "input_handler.hpp"
#include "config/shortcuts.hpp"
#include "widgets/page.hpp"
#include "widgets/command.hpp"

namespace InputHandler {
    namespace {
        WINDOW *fake_window;
    }

    void init()
    {
        // ncurses inputs init
        fake_window = newwin(0, 0, LINES-1, COLS-1);
        raw();
        keypad(fake_window, TRUE);
        noecho();
    }

    void free()
    {
        delwin(fake_window);
    }

    void wait_and_read()
    {
        while (TRUE) {
            // Here we only handle shortcuts (some redirect to the widgets)
            const uint16_t c = wgetch(fake_window);
            const std::string *command = Config::Shortcuts::get_command(c);
            if (command)
                CommandsHandler::exec(command);
        }
    }
}

