#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#include <string>

namespace YAML { class Node; }

class Config {
    public:
        Config(const YAML::Node &config);

        const std::string& get_welcome_url() const;
        const std::string& get_search_url() const;
        bool are_cookies_accepted() const;
        const std::string& get_cookies_storage_path() const;
        const std::string& get_media_display_command() const;

    private:
        std::string welcome_url, search_url;
        bool _are_cookies_accepted;
        std::string cookies_storage_path;
        std::string media_display_command;
};

#endif
