#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <string>

class App;

namespace Commands::Global {
    const std::string &get_current_url(App *app);
}

#endif
