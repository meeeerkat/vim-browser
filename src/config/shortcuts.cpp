#include "config/shortcuts.hpp"
#include "helpers/config.hpp"


namespace Config {
    Shortcuts::Shortcuts(const std::string &config_dir)
    {
        std::ifstream file = Helpers::Config::open_file(config_dir, "shortcuts");

        char shortcut;
        std::string command;
        while(file) {
            shortcut = file.get();
            // Separator dumping (only for config file readability)
            file.get();
            std::getline(file, command);
            shortcut_to_command[shortcut] = command;
        }

        file.close();
    }

    const std::string *Shortcuts::get_command(uint16_t shortcut) const
    {
        if (shortcut_to_command.count(shortcut) == 0)
            return NULL;
        return &shortcut_to_command.at(shortcut);
    }
}
