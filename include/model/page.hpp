#ifndef __MODEL_PAGE_HPP__
#define __MODEL_PAGE_HPP__

//#include <lexbor/html/html.h>
#include <string>


class Page {
    public:
        Page();
        ~Page();
        void set_url(std::string url);
        //void load(void (*callback) (void*), void *callback_params);
        //void set_url_and_load(char *url, void (*callback) (void*), void *callback_params);
        std::string *get_title();
    private:
        std::string url;
        //lxb_html_document_t *doc;
};

#endif
