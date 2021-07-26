#ifndef __CONFIG_CATEGORY_H__
#define __CONFIG_CATEGORY_H__

#include <fstream>
#include <string>


namespace Config {

    class Category {

        public:
            Category(const std::string &config_dir, const std::string &config_file);
            void finish_build();

        protected:
            std::ifstream file;
            
    };
}

#endif
