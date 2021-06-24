#include <assert.h>
#include <regex>
#include "helpers.hpp"

namespace Helpers {
    void fix_url(std::string *url)
    {
        if (std::regex_match(*url, std::regex("^(https://|http://)")))
            return;

        if (std::regex_match(*url, std::regex("\\w\+\\.\\w\+$"))) {
            url->insert(0, "https://www.");
            return;
        }

        url->insert(0, "https://duckduckgo.com/?q=");

    }
}


/*
 * OLD C FUNCTION
 *
 *
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
*/

