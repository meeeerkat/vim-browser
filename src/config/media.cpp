#include "config/media.hpp"
#include <cassert>
#include <yaml-cpp/yaml.h>


namespace Config {
    
    Media *media = nullptr;

    Media::Media(const std::string &config_dir)
    {
        assert(!media);

        YAML::Node config = YAML::LoadFile(config_dir + "media.yaml");

        display_command = config["display_command"].as<std::string>();
    }

    const std::string& Media::get_display_command() const
    {
        return display_command;
    }

}
