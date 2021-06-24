#ifndef __MODEL_PAGELOADER_HPP__
#define __MODEL_PAGELOADER_HPP__

#include <stdlib.h>
#include <inttypes.h>
#include <curl/curl.h>
#include <string.h>
#include "model/page.hpp"

#define HTML_BUFFER_SIZE 10000

struct load_page_params;

namespace PageLoader {
    void init();
    void free();
    void load_async(Page *page, void (*callback) (void*), void *callback_params);
};


#endif
