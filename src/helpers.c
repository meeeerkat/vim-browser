#include <ctype.h>
#include "helpers.h"


bool helpers_string_is_empty(char *str)
{
    while(*str != '\0' && isspace(*str))
        str++;

    return *str == '\0';
}
