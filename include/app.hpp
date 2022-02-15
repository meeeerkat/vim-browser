#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include <string>

class BrowserConfig;
class DocumentLoader;
class InputHandler;
namespace Commands { class Handler; }
namespace Widgets {
    class Page;
    class Command;
    class Tabs;
}

// Mostly only initialisation & modules management
class App {

    public:
        App();
        ~App();
        
        void wait_and_handle_input();

        void pause();
        void unpause();
        void quit_when_possible();
        
        int exec(const std::string &command);

        BrowserConfig *getConfig();
        DocumentLoader *getDocumentLoader();
        InputHandler *getInputHandler();

        Widgets::Command *getCommandWidget();
        Widgets::Page *getPageWidget();
        Widgets::Tabs *getTabsWidget();

    private:
        // helpers
        BrowserConfig *config;
        DocumentLoader *document_loader;
        InputHandler *input_handler;
        Commands::Handler *commands_handler;
        // widgets
        Widgets::Page *page_widget;
        Widgets::Command *command_widget;
        Widgets::Tabs *tabs_widget;

        bool should_quit;
};


#endif
