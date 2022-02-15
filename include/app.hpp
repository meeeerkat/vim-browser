#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include <string>

namespace Config { class Manager; }
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

        DocumentLoader *getDocumentLoader();
        InputHandler *getInputHandler();

        Widgets::Command *getCommandWidget();
        Widgets::Page *getPageWidget();
        Widgets::Tabs *getTabsWidget();

    private:
        // helpers
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
