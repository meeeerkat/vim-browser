#include "helpers/config.hpp"

namespace Helpers::Config {

    std::ifstream open_file(const std::string &config_dir, const std::string &config_file)
    {
        std::string path = config_dir + config_file;
        std::ifstream file(path);
        if(!file.is_open()) {
            perror(("Cannot open " + config_file + " config file.").c_str());
            exit(EXIT_FAILURE);
        }

        return file;
    }

}
