#include "config.hpp"
#include <yaml-cpp/yaml.h>


Config::Config(const YAML::Node &config)
{
    YAML::Node general = config["general"];
    welcome_url = general["welcome_url"].as<std::string>();
    search_url = general["search_url"].as<std::string>();
    _are_cookies_accepted = general["cookies_accept"].as<bool>();
    cookies_storage_path = general["cookies_storage_path"].as<std::string>();

    YAML::Node media = config["media"];
    media_display_command = media["display_command"].as<std::string>();
}

const std::string& Config::get_welcome_url() const
{
    return welcome_url;
}

const std::string& Config::get_search_url() const
{
    return search_url;
}

bool Config::are_cookies_accepted() const
{
    return _are_cookies_accepted;
}

const std::string& Config::get_cookies_storage_path() const
{
    return cookies_storage_path;
}

const std::string& Config::get_media_display_command() const
{
    return media_display_command;
}


