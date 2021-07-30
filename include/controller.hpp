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
class Controller {

    public:
        Controller();
        ~Controller();

        static void pause();
        static void unpause();

        static Controller *instance;
    
        // helpers
        static DocumentLoader *document_loader;
        static InputHandler *input_handler;
        static Commands::Handler *commands_handler;
        // widgets
        static Widgets::Page *page_widget;
        static Widgets::Command *command_widget;
        static Widgets::Tabs *tabs_widget;

    private:
        static void print_message(const std::string &message);
        static int exec(const std::string &command);
};


#endif
