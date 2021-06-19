#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <stdlib.h>
#include "model/loader.h"
#include "model/page.h"

void controller_init();
void controller_free();
void controller_open_in_current_tab(char *url);
void controller_open_in_new_tab(char *url);


#endif
