#include <stdio.h>
#include <curl/curl.h>
#include <unistd.h>
#include "controller.h"


int main()
{
    controller_init();
    controller_open_in_current_tab("https://www.google.fr");
    sleep(1);
    controller_open_in_new_tab("https://www.duckduckgo.fr");
    sleep(1);
    controller_open_in_new_tab("https://www.duckduckgo.fr");
    sleep(1);
    controller_open_in_new_tab("https://www.duckduckgo.fr");
    sleep(1);
    controller_open_in_new_tab("https://www.duckduckgo.fr");
    sleep(1);
    controller_free();
    
    return 0;
}
