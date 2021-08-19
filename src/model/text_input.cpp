#include "model/text_input.hpp"
#include <ncurses.h>


namespace Model {

TextInput::TextInput()
    : cursor{0}
{

}


void TextInput::insert_char(char c)
{
    value.insert(cursor, 1, c);
    cursor++;
}

TextInput::InputState TextInput::handle_input(uint16_t code)
{
    switch (code) {
        case '\n':
        case KEY_ENTER:
            return InputState::Sent;

        case KEY_DC:
            if (value.length() == 0)
                return InputState::Canceled;
            if (cursor < value.length())
                value.erase(cursor, 1);
            else if (cursor == value.length() && value.length() > 0) {
                value.erase(cursor-1, 1);
                cursor--;
            }
            break;

        case KEY_BACKSPACE:
        case 127:
            if (value.length() == 0)
                return InputState::Canceled;
            if (cursor != 0) {
                value.erase(cursor-1, 1);
                cursor--;
            }
            break;

        case KEY_LEFT:
            if (cursor > 0)
                cursor--;
            break;

        case KEY_RIGHT:
            if (cursor < value.length())
                cursor++;
            break;

        default:
            insert_char((char) code);
            break;
    }

    return InputState::WaitingInput;
}

void TextInput::reset()
{
    set_value("");
}
void TextInput::set_value(const std::string &new_value)
{
    value = new_value;
    cursor = value.length();
}
const std::string TextInput::get_value() const
{
    return value;
}

uint16_t TextInput::get_cursor() const
{
    return cursor;
}

}
