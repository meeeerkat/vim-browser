#include "helpers/url.hpp"
#include <regex>

namespace Helpers::Url {
    void fix(std::string &url, const std::string &search_url, const std::string &base)
    {
        if (std::regex_match(url, std::regex("^https?:\\/\\/.*")))
            return;

        if (std::regex_match(url, std::regex("^\\/\\/\\w+([\\.\\/]\\w+)+.*$"))) {
            url.insert(0, "https:");
            return;
        }

        if (std::regex_match(url, std::regex("^\\w+([\\.\\/]\\w+)+.*$"))) {
            url.insert(0, "https://");
            return;
        }

        if (base.empty()) {
            url = std::regex_replace(search_url, std::regex("\\$SEARCH_STRING"), url);
            return;
        }

        url.insert(0, base);
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
