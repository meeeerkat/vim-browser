#include <assert.h>
#include <regex>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "helpers.hpp"

namespace Helpers {
    void fix_url(std::string *url)
    {
        if (std::regex_match(*url, std::regex("^(https://|http://).*")))
            return;

        if (std::regex_match(*url, std::regex("\\w\+\\.\\w\+$"))) {
            url->insert(0, "https://www.");
            return;
        }
        url->insert(0, "https://duckduckgo.com/?q=");
    }

    const char *get_home_dir_path()
    {
        struct passwd *pw = getpwuid(getuid());
        return pw->pw_dir;
    }
}
