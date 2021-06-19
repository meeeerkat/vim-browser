#ifndef __MODEL_H__
#define __MODEL_H__

#include <stdlib.h>
#include <inttypes.h>
#include "page.h"


void model_init();
void model_load_page_async(char* url, page_t *page, void (*callback) (void*), void *callback_params);
void model_free();


#endif
