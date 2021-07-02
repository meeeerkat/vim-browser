#include <regex>
#include "helpers/url.hpp"

namespace Helpers::Url {
    void fix(std::string *url)
    {
        if (std::regex_match(*url, std::regex("^(https://|http://).*")))
            return;

        if (std::regex_match(*url, std::regex("\\w\+\\.\\w\+$"))) {
            url->insert(0, "https://www.");
            return;
        }
        url->insert(0, "https://duckduckgo.com/?q=");
    }
}
