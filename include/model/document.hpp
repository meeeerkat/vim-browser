#ifndef __MODEL_DOCUMENT_H__
#define __MODEL_DOCUMENT_H__
#include <string>
#include "model/element.hpp"

class Document {
    public:
        Document();
        ~Document();
    private:
        std::string title;
        Element *body;
};

#endif
