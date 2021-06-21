#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>
#include "helpers.h"


bool helpers_string_is_empty(char *str)
{
    while(*str != '\0' && isspace(*str))
        str++;

    return *str == '\0';
}

void helpers_string_prepend(char *dest, const char *source)
{
    size_t len = strlen(source);
    memmove(dest + len, dest, strlen(dest) + 1);
    memcpy(dest, source, len);
}



char *helpers_url_fix(char *url)
{
    regex_t scheme_reg, domain_reg;
    int state = regcomp(&scheme_reg, "^(https://|http://)", 0);
    // state != 0 => compilation error
    assert(state == 0);
    if (state != 0) {
        regfree(&scheme_reg);
        return NULL;
    }
    
    char *fixed_url = malloc((strlen(url)+100) * sizeof(char));

    // Fixing the scheme
    if (regexec(&scheme_reg, url, 0, NULL, 0) != REG_NOMATCH) {
        // Nothing to fix
        strcpy(fixed_url, url);
        regfree(&scheme_reg);
        return fixed_url;
    }
    regfree(&scheme_reg);
 
    state = regcomp(&domain_reg, "\\w\+\\.\\w\+$", REG_EXTENDED);
    // state != 0 => compilation error
    assert(state == 0);
    if (state != 0) {
        regfree(&domain_reg);
        return NULL;
    }

    if (regexec(&domain_reg, url, 0, NULL, 0) != REG_NOMATCH) {
        // Only the scheme was forgot
        sprintf(fixed_url, "https://www.%s", url);
        regfree(&domain_reg);
        return fixed_url;
    }
    regfree(&domain_reg);

    // If we're here then the url is actually just a search string
    // TODO: support different search engines
    const char *search_engine_url_format = "https://duckduckgo.com/?q=%s";
    sprintf(fixed_url, search_engine_url_format, url);
    return fixed_url;
}
