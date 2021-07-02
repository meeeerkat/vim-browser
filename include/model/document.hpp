#ifndef __MODEL_DOCUMENT_H__
#define __MODEL_DOCUMENT_H__
#include <string>
#include <gumbo.h>
#include "model/element.hpp"
#include "helpers/callback.hpp"

class Document {
    public:
        Document(const std::string *url);
        Document(const std::string *url, Helpers::Callback *on_loaded_callback);
        ~Document();

        const std::string *get_title() const;
        const std::string *get_url() const;
        
        void on_loaded(GumboOutput* output);

    private:
        std::string url;
        Helpers::Callback *on_loaded_callback;

        std::string title;
        Element *body;
};

#endif
