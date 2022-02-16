#ifndef __COMMANDS_GLOBAL_HPP__
#define __COMMANDS_GLOBAL_HPP__

#include <string>

// This file's use was removed when libvim was factorised out of this project
// but the feature it uses will be re-implemented in libvim soon

class App;

namespace Commands::Global {
    const std::string &get_current_url(App *app);
}

#endif
