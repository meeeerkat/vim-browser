#ifndef __MODEL_DOCUMENT_H__
#define __MODEL_DOCUMENT_H__
#include <string>
#include <ncurses.h>
#include <gumbo.h>
#include <functional>
#include "model/nodes/body.hpp"
#include "model/nodes/interactive_element.hpp"
#include "helpers/http_request.hpp"

class DocumentLoader;

class Document {
    public:
        Document(const Helpers::HttpRequest &request);
        Document(const Helpers::HttpRequest &request, std::function<void()> on_loaded_callback);
        ~Document();

        const std::string &get_title() const;
        const Helpers::HttpRequest &get_request() const;
        // just a public shortcut for DocumentLoader::is_loading(Document*)
        void on_loaded(GumboOutput* output);
        void on_loading_failed(const std::string &error_code);

        void printw(WINDOW *window, Nodes::PrintingOptions printing_options = Nodes::PrintingOptions{}) const;

        Nodes::InteractiveElement *get_interactive_element(const std::string &id);

    private:
        Helpers::HttpRequest request;
        std::function<void()> on_loaded_callback;


        std::string title;
        Nodes::Body *body;
        Nodes::BuildData build_data;

        void parse_head(GumboElement *head);
        void parse_title(GumboElement *title_element);

        bool is_loaded;

};

#endif
