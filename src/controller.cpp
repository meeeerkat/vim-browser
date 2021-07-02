#include <string.h>
#include <pthread.h>
#include "controller.hpp"
#include "model/document_loader.hpp"
#include "widgets/tabs.hpp"
#include "widgets/page.hpp"
#include "widgets/command.hpp"
#include "input_handler.hpp"
#include "commands/open.hpp"
#include "commands/handler.hpp"
#include "config/main.hpp"


namespace Controller {
    void init()
    {
        Config::init();

        // ncurses init
        initscr();

        // helpers init
        DocumentLoader::init();
        InputHandler::init();
        CommandsHandler::init(CommandWidget::print_message);

        // widgets init
        PageWidget::init();
        CommandWidget::init(CommandsHandler::exec);
        TabsWidget::init();

        // Opening base window
        Commands::open_in_new_tab("https://duckduckgo.com");

        // Setup complete, now everything is done after an user command
        InputHandler::wait_and_read();
    }

    void free()
    {
        // helpers freeing
        DocumentLoader::free();
        InputHandler::free();
        CommandsHandler::free();

        // widgets freeing
        PageWidget::free();
        CommandWidget::free();
        TabsWidget::free();

        // ncurses closing
        endwin();

        Config::free();
    }


}
