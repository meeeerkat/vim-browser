#include <unistd.h>
#include "commands/scroll.hpp"
#include "widgets/page.hpp"
#include "app.hpp"


namespace Commands {
    int scroll_exec(App *app, int argc, char **argv, std::string *error_message)
    {
        bool is_absolute = false;
        bool is_negative = false;

        char opt;
        // getopt config
        opterr = 0; // No errors on stderr
        optind = 0; // Reset getopt cursor (need to do it every time)
        while ((opt = getopt(argc, argv, "an")) != -1) {
            switch (opt) {
                case 'a':
                    is_absolute = true;
                    break;
                case 'n':
                    is_negative = true;
                    break;
                default:
                    break;
            }
        }
        if (optind + 1 != argc) {
            *error_message = "Usage: scroll [-a] line";
            return -1;
        }

        int line = std::stoi(std::string(argv[optind]));
        if (is_negative)
            line = -line;
        if (!is_absolute)
            line += app->getPageWidget()->get_start_line();

        app->getPageWidget()->scroll_to(line);

        return 0;
    }
}
