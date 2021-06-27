#ifndef __MODEL_PAGELOADER_HPP__
#define __MODEL_PAGELOADER_HPP__

#include "model/page.hpp"

#define HTML_BUFFER_SIZE 10000

struct load_page_params;

namespace PageLoader {
    void init();
    void free();
    void load_async(lxb_html_document_t *doc, std::string url, void (*callback) (void*), void *callback_params);
};


#endif
