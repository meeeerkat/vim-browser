#include "config/general.hpp"
#include <cassert>
#include <iostream>
#include <yaml-cpp/yaml.h>


namespace Config {
    
    General *general = nullptr;

    General::General(const std::string &config_dir)
    {
        assert(!general);

        YAML::Node config = YAML::LoadFile(config_dir + "general.yaml");

        welcome_url = config["welcome_url"].as<std::string>();
        search_url = config["search_url"].as<std::string>();
        cookies_accept = config["cookies_accept"].as<bool>();
        cookies_storage_path = config["cookies_storage_path"].as<std::string>();
    }

    const std::string& General::get_welcome_url() const
    {
        return welcome_url;
    }

    const std::string& General::get_search_url() const
    {
        return search_url;
    }
    
    const bool& General::are_cookies_accepted() const
    {
        return cookies_accept;
    }
   
    const std::string& General::get_cookies_storage_path() const
    {
        return cookies_storage_path;
    }

}
