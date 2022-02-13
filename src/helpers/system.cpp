#include <stdlib.h>


namespace Helpers::System {
    const char *get_home_dir_path()
    {
        return getenv("HOME");
    }
}
