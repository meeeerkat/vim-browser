#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "helpers/system.hpp"


namespace Helpers::System {
    const char *get_home_dir_path()
    {
        struct passwd *pw = getpwuid(getuid());
        return pw->pw_dir;
    }
}
