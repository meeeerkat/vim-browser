#ifndef __CONFIG_MANAGER_H__
#define __CONFIG_MANAGER_H__

#include <string>
#include "config/shortcuts.hpp"

class Shortcuts;

namespace Config {
    // This class's job is only to instantiate & clean all the configs
    class Manager {
        public:
            Manager();
            ~Manager();
            
            Shortcuts *shortcuts;

        private:
            std::string dir_path;
    };
}

#endif
