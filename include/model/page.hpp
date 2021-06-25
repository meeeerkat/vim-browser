#ifndef __MODEL_PAGE_HPP__
#define __MODEL_PAGE_HPP__

#include <lexbor/html/html.h>
#include <string>


class Page {
    public:
        Page();
        ~Page();
        void set_url(std::string url);
        const std::string *get_url();
        char *get_title();
        
        lxb_html_document_t *doc;
    private:
        std::string url;
};

#endif
