#include "config/shortcuts.hpp"
#include <yaml-cpp/yaml.h>


namespace Config {

    Shortcuts *shortcuts = nullptr;

    Shortcuts::Shortcuts(const std::string &config_dir)
    {
        YAML::Node config = YAML::LoadFile(config_dir + "shortcuts");

        char shortcut;
        for (YAML::const_iterator it=config.begin(); it != config.end(); it++) {
            shortcut = it->first.as<char>();
            shortcut_to_command[shortcut] = it->second.as<std::string>();
        }
    }

    const std::string *Shortcuts::get_command(uint16_t shortcut) const
    {
        if (shortcut_to_command.count(shortcut) == 0)
            return NULL;
        return &shortcut_to_command.at(shortcut);
    }
}
