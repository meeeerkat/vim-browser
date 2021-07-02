#ifndef __MODEL_DOCUMENTLOADER_HPP__
#define __MODEL_DOCUMENTLOADER_HPP__

class Document;

namespace DocumentLoader {
    void init();
    void free();
    void load_async(Document* doc);
};


#endif
