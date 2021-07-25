#include <map>
#include <fstream>
#include "config/shortcuts.hpp"

namespace Config {
    Shortcuts::Shortcuts(const std::string &config_dir)
    {
        std::string path = config_dir + "shortcuts";
        std::ifstream file(path);
        if(!file.is_open()) {
            perror("Cannot open shortcuts' config file.");
            exit(EXIT_FAILURE);
        }

        char shortcut;
        std::string command;
        while(file) {
            shortcut = file.get();
            // Separator dumping (only for config file readability)
            file.get();
            std::getline(file, command);
            shortcut_to_command[shortcut] = command;
        }
    }

    const std::string *Shortcuts::get_command(uint16_t shortcut) const
    {
        if (shortcut_to_command.count(shortcut) == 0)
            return NULL;
        return &shortcut_to_command.at(shortcut);
    }
}
