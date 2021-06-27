#ifndef __MODEL_DOCUMENTLOADER_HPP__
#define __MODEL_DOCUMENTLOADER_HPP__

#include "model/document.hpp"

namespace DocumentLoader {
    void init();
    void free();
    void load_async(std::string url, void (*callback) (Document*, void*), void *callback_params);
};


#endif
