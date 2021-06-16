#include <stdio.h>
#include <curl/curl.h>
#include <unistd.h>
#include "controller.h"


int main()
{
    controller_init();
    controller_free();
    
    return 0;
}
