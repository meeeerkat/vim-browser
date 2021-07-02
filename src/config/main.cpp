#include "config/main.hpp"
#include "helpers/system.hpp"
#include "config/shortcuts.hpp"


namespace Config {
    namespace {
        std::string dir_path;
    }

    void init()
    {
        dir_path = std::string(Helpers::System::get_home_dir_path()) + "/.vim-browser/";
        Shortcuts::init(&dir_path);
    }
    
    void free()
    {
    
    }
}

