#ifndef __HELPERS_CONFIG_H__
#define __HELPERS_CONFIG_H__

#include <fstream>
#include <string>

namespace Helpers::Config {
    std::ifstream open_file(const std::string &config_dir, const std::string &config_file);
}

#endif
