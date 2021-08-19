#ifndef __CONFIG_GENERAL_H__
#define __CONFIG_GENERAL_H__

#include <string>


namespace Config {
    class General {

        public:
            General(const std::string &config_dir);
            const std::string& get_welcome_url() const;
            const std::string& get_search_url() const;
            const bool& are_cookies_accepted() const;
            const std::string& get_cookies_storage_path() const;

        private:
            std::string welcome_url;
            std::string search_url;
            bool cookies_accept;
            std::string cookies_storage_path;
    };
    
    extern General *general;
}

#endif
