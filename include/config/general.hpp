#ifndef __CONFIG_GENERAL_H__
#define __CONFIG_GENERAL_H__

#include <string>


namespace Config {
    class General {

        public:
            General(const std::string &config_dir);
            const std::string& get_welcome_url() const;
            const std::string& get_search_url() const;

        private:
            std::string welcome_url;
            std::string search_url;
    };
    
    extern General *general;
}

#endif
