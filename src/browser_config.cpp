#include "browser_config.hpp"
#include <yaml-cpp/yaml.h>


BrowserConfig::BrowserConfig(const YAML::Node &config)
    : Config(config)
{
    YAML::Node general = YAML::Node(config["general"]);
    welcome_url = general["welcome_url"].as<std::string>();
    search_url = general["search_url"].as<std::string>();
    _are_cookies_accepted = general["cookies_accept"].as<bool>();
    cookies_storage_path = general["cookies_storage_path"].as<std::string>();

    YAML::Node media = YAML::Node(config["media"]);
    media_display_command = media["display_command"].as<std::string>();
}

const std::string& BrowserConfig::get_welcome_url() const
{
    return welcome_url;
}

const std::string& BrowserConfig::get_search_url() const
{
    return search_url;
}

bool BrowserConfig::are_cookies_accepted() const
{
    return _are_cookies_accepted;
}

const std::string& BrowserConfig::get_cookies_storage_path() const
{
    return cookies_storage_path;
}

const std::string& BrowserConfig::get_media_display_command() const
{
    return media_display_command;
}


