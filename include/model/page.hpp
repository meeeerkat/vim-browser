#ifndef __MODEL_PAGE_HPP__
#define __MODEL_PAGE_HPP__

#include <lexbor/html/html.h>
#include <string>


class Page {
    enum State {Empty, Loading, Loaded};

    public:
        Page();
        ~Page();
        void load(std::string url, void (*on_page_loaded_callback) (void*), void *on_page_loaded_callback_args);
        const std::string *get_url();
        char *get_title();

    private:
        State state;
        std::string url;
        lxb_html_document_t *doc;

        // To change the state & call custom callback
        static void on_page_loaded(Page *page);
        void (*on_page_loaded_callback) (void*);
        void *on_page_loaded_callback_args;
};

#endif
