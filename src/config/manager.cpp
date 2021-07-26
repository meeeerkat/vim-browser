#include "config/manager.hpp"
#include <cassert>
#include "helpers/system.hpp"
#include "config/general.hpp"
#include "config/shortcuts.hpp"


namespace Config {

    Manager *Manager::instance = nullptr;
    General *Manager::general = nullptr;
    Shortcuts *Manager::shortcuts = nullptr;

    Manager::Manager()
    {
        assert(!instance);
        instance = this;

        dir_path = std::string(Helpers::System::get_home_dir_path()) + "/.vim-browser/";

        general = new General(dir_path);
        shortcuts = new Shortcuts(dir_path);
    }
    
    Manager::~Manager()
    {
        delete general;
        delete shortcuts;
    }
}
