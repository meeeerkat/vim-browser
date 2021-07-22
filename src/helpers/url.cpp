#include <regex>
#include "helpers/url.hpp"

namespace Helpers::Url {
    void fix(std::string *url, std::string base)
    {
        if (std::regex_match(*url, std::regex("^(https://|http://).*")))
            return;

        if (std::regex_match(*url, std::regex("\\w\+\\.\\w\+$"))) {
            url->insert(0, "https://www.");
            return;
        }

        if (base.empty()) {
            url->insert(0, "https://lite.duckduckgo.com/lite/?q=");
            return;
        }

        url->insert(0, base);
    }
    
    std::string get_base(const std::string &url)
    {
        std::regex rgx("(.*:\\/\\/(?:\\w+\\.?)+)");
        std::smatch match;
        if (std::regex_search(url.begin(), url.end(), match, rgx))
            return match[1];
        return "";
    }
}
