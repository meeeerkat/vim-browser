#include "config/category.hpp"


namespace Config {
    Category::Category(const std::string &config_dir, const std::string &config_file)
    {
    }

    void Category::finish_build()
    {
        file.close();
    }
}
