#include "input_handler.hpp"


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

uint16_t InputHandler::get_input()
{
    return wgetch(fake_window);
}

void InputHandler::wait_for_input()
{
    get_input();
}

