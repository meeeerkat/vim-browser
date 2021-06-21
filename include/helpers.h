#ifndef __HELPERS_H__
#define __HELPERS_H__

#include <stdlib.h>
#include <stdbool.h>

bool helpers_string_is_empty(char *str);
void helpers_string_prepend(char *dest, const char *source);
char *helpers_url_fix(char *url);

#endif
