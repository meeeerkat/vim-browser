#ifndef __APP_HPP__
#define __APP_HPP__

#include <string>
#include "vim/app.hpp"

class Config;
class DocumentLoader;
namespace Commands { class Handler; }
namespace Widgets {
    class Page;
    class Tabs;
}

// Mostly only initialisation & modules management
class App : public Vim::App {

    public:
        App(const YAML::Node &yaml_config);
        ~App();
        
        void pause();
        void unpause();

        Config *get_config();
        DocumentLoader *get_document_loader();

        Widgets::Page *get_page_widget();
        Widgets::Tabs *get_tabs_widget();

    private:
        // helpers
        Config *config;
        DocumentLoader *document_loader;
        // widgets
        Widgets::Page *page_widget;
        Widgets::Tabs *tabs_widget;
};


#endif
