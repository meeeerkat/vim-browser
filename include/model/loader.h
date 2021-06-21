#ifndef __MODEL_LOADER_H__
#define __MODEL_LOADER_H__

#include <stdlib.h>
#include <inttypes.h>
#include "model/page.h"


void model_loader_init();
void model_loader_load_page_async(model_page_t *page, void (*callback) (void*), void *callback_params);
void model_loader_free();


#endif
