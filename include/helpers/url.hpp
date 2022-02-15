#ifndef __HELPERS_URL_HPP__
#define __HELPERS_URL_HPP__

#include <string>

namespace Helpers::Url {
    void fix(std::string &url, const std::string &search_url = "", const std::string &base = "");
    std::string get_base(const std::string &url);
}

#endif
