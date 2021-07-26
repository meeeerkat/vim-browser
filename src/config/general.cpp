#include "config/general.hpp"
#include "helpers/config.hpp"


namespace Config {

    General::General(const std::string &config_dir)
    {
        std::ifstream file = Helpers::Config::open_file(config_dir, "general");

        std::string comments;

        std::getline(file, comments);
        std::getline(file, welcome_url);

        std::getline(file, comments);
        std::getline(file, search_url);

        file.close();
    }

    const std::string& General::get_welcome_url() const
    {
        return welcome_url;
    }

    const std::string& General::get_search_url() const
    {
        return search_url;
    }

}
