#ifndef __CONFIG_MANAGER_H__
#define __CONFIG_MANAGER_H__

#include <string>
#include <fstream>


namespace Config {

    class General;
    class Shortcuts;

    // This class's job is only to instantiate & clean all the configs
    class Manager {
        public:
            Manager();
            ~Manager();
            
            static Manager *instance;

            static General *general;
            static Shortcuts *shortcuts;

        private:
            std::string dir_path;
    };
}

#endif
