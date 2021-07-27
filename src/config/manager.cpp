#include "config/manager.hpp"
#include <cassert>
#include <iostream>
#include "helpers/system.hpp"
#include "config/general.hpp"
#include "config/shortcuts.hpp"


namespace Config {

    void load()
    {
        std::string dir_path = std::string(Helpers::System::get_home_dir_path()) + "/.vim-browser/";

        general = new General(dir_path);
        shortcuts = new Shortcuts(dir_path);
    }

    void free()
    {
        delete general;
        delete shortcuts;
    }

}
