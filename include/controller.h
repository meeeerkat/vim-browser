#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <stdlib.h>
#include "model.h"
#include "page.h"

void controller_init();
void controller_free();
int8_t controller_open_in_current_tab(char *url);
int8_t controller_open_in_new_tab(char *url);



#endif
