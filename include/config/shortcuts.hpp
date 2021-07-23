#ifndef __CONFIG_SHORTCUTS_H__
#define __CONFIG_SHORTCUTS_H__

#include <string>

namespace Config::Shortcuts {
    void init(const std::string &config_dir);
    const std::string *get_command(uint16_t shortcut);
}

#endif
