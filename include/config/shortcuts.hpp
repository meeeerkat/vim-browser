#ifndef __CONFIG_SHORTCUTS_H__
#define __CONFIG_SHORTCUTS_H__

#include <map>
#include <string>


namespace Config {
    class Shortcuts {

        public:
            Shortcuts(const std::string &config_dir);
            const std::string *get_command(uint16_t shortcut) const;

        private:
            std::map<uint16_t, std::string> shortcut_to_command;
    };
}

#endif
