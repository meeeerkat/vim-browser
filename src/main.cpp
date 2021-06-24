#include <stdio.h>
#include <curl/curl.h>
#include <unistd.h>
#include "controller.hpp"


int main()
{
    Controller::init();
    sleep(2);
    Controller::free();
    
    return 0;
}
