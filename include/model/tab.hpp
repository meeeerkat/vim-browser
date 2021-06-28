#ifndef __MODEL_PAGE_HPP__
#define __MODEL_PAGE_HPP__

#include <string>
#include "model/document.hpp"

/*
 * Necessary class to hold the url & provide an invariant
 * (if url is not empty then the document is loading or already loaded)
 * Will also choose which loader to use depending on the url (http(s):// or files:// ...)
 * (use curl loader if it's a remote ressource and another loader for files)
 */
class Tab {
    enum State {Empty, Loading, Loaded};

    public:
        Tab();
        ~Tab();
        void load(std::string url, void (*on_tab_loaded_callback) (void*), void *on_tab_loaded_callback_args);
        const std::string *get_url();
        Document *get_document();

    private:
        State state;
        std::string url;
        Document *doc;

        // To change the state & call custom callback
        static void on_tab_loaded(Document *doc, Tab *tab);
        void (*on_tab_loaded_callback) (void*);
        void *on_tab_loaded_callback_args;
};

#endif
