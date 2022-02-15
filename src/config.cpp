#include "config.hpp"
#include <yaml-cpp/yaml.h>


Config::Config(const YAML::Node &config)
{
    // shortcuts config
    YAML::Node shortcuts = config["shortcuts"];
    for (YAML::const_iterator it=shortcuts.begin(); it != shortcuts.end(); it++) {
        char shortcut = it->first.as<char>();
        shortcut_to_command[shortcut] = it->second.as<std::string>();
    }
}

const std::string *Config::get_command_from_shortcut(uint16_t shortcut) const
{
    if (shortcut_to_command.count(shortcut) == 0)
        return NULL;
    return &shortcut_to_command.at(shortcut);
}
