#include <stdio.h>
#include <curl/curl.h>
#include <unistd.h>
#include "controller.hpp"


int main()
{
    Controller::init();
    Controller::free();
    
    return 0;
}
