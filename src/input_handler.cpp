#include "input_handler.hpp"
#include <cassert>
#include "config/shortcuts.hpp"
#include "widgets/page.hpp"
#include "widgets/command.hpp"
#include "config/manager.hpp"
#include "config/shortcuts.hpp"

InputHandler::InputHandler()
{
    // ncurses inputs init
    fake_window = newwin(0, 0, LINES-1, COLS-1);
    raw();
    keypad(fake_window, TRUE);
    noecho();
}

InputHandler::~InputHandler()
{
    delwin(fake_window);
}

uint16_t InputHandler::get_char()
{
    return wgetch(fake_window);
}

void InputHandler::wait_and_read(int (*exec) (const std::string&))
{
    while (true) {
        // Here we only handle shortcuts (some redirect to the widgets)
        const uint16_t c = wgetch(fake_window);
        const std::string *command = Config::Manager::shortcuts->get_command(c);
        if (command)
            exec(*command);
    }
}
