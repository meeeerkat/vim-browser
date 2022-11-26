#include "app.hpp"
#include <stdlib.h>
#include <iostream>
#include <yaml-cpp/yaml.h>


int main()
{
    std::string path = std::string(getenv("HOME")) + "/.vim-browser.yaml";
    YAML::Node yaml_config;
    try {
      yaml_config = YAML::LoadFile(path);
    } catch (std::exception& e) {
      std::cerr << "Can't open config file " << path << "\n";
      exit(1);
    }

    App app(yaml_config);
    app.wait_and_handle_input();

    return 0;
}
