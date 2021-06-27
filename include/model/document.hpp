#ifndef __MODEL_DOCUMENT_H__
#define __MODEL_DOCUMENT_H__
#include <string>
#include "model/element.hpp"

class Document {
    public:
        Document(const std::string *source);
        ~Document();

        const std::string *get_title() const;
    private:
        std::string title;
        Element *body;
};

#endif
