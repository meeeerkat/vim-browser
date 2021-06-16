#ifndef __MODEL_H__
#define __MODEL_H__

#include <stdlib.h>
#include <inttypes.h>
#include "page.h"


void model_init();
int8_t model_load_page(char* url, page_t *page);
void model_free();


#endif
