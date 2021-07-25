#include "config/manager.hpp"
#include "helpers/system.hpp"

namespace Config {
    Manager::Manager()
    {
        dir_path = std::string(Helpers::System::get_home_dir_path()) + "/.vim-browser/";
        shortcuts = new Shortcuts(dir_path);
    }
    
    Manager::~Manager()
    {
        delete shortcuts;
    }
}
