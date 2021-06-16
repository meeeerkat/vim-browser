#include <stdio.h>
#include <curl/curl.h>
#include <unistd.h>
#include "controller.h"


int main()
{
    controller_init();
    controller_open_in_current_tab("https://www.google.fr");
    controller_free();
    
    return 0;
}
