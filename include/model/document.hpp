#ifndef __MODEL_DOCUMENT_H__
#define __MODEL_DOCUMENT_H__
#include <string>
#include <gumbo.h>
#include "model/nodes/body.hpp"
#include "model/nodes/interactive_element.hpp"
#include "helpers/callback.hpp"


class Document {
    public:
        Document(const std::string *url);
        Document(const std::string *url, Helpers::Callback *on_loaded_callback);
        ~Document();

        const std::string *get_title() const;
        const std::string *get_url() const;
        // just a public shortcut for DocumentLoader::is_loading(Document*)
        bool is_loading() const;
        void on_loaded(GumboOutput* output);

        void printw(WINDOW *window, Nodes::PrintingOptions printing_options = Nodes::PrintingOptions{}) const;

        Nodes::InteractiveElement *get_interactive_element(const std::string &id);

    private:
        std::string url;
        Helpers::Callback *on_loaded_callback;

        std::string title;
        Nodes::Body *body;
        Nodes::BuildData build_data;

        void parse_head(GumboElement *head);
        void parse_title(GumboElement *title_element);

};

#endif
