#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <map>
#include <string>

namespace YAML { class Node; }

class Config {
    public:
        Config(const YAML::Node &config);

        const std::string *get_command_from_shortcut(uint16_t shortcut) const;

    private:
        std::map<uint16_t, std::string> shortcut_to_command;
};

#endif
