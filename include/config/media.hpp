#ifndef __CONFIG_MEDIA_H__
#define __CONFIG_MEDIA_H__

#include <string>


namespace Config {
    class Media {

        public:
            Media(const std::string &config_dir);
            const std::string& get_display_command() const;

        private:
            std::string display_command;
    };
    
    extern Media *media;
}

#endif
