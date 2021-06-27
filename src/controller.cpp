#include <string.h>
#include <pthread.h>
#include "controller.hpp"
#include "model/page_loader.hpp"
#include "widgets/tabs.hpp"
#include "widgets/page.hpp"
#include "widgets/command.hpp"
#include "input_handler.hpp"
#include "commands/open.hpp"
#include "commands/handler.hpp"


namespace Controller {
    void init()
    {
        // ncurses init
        initscr();

        // helpers init
        PageLoader::init();
        InputHandler::init();
        CommandsHandler::init(CommandWidget::print_message);

        // widgets init
        PageWidget::init();
        CommandWidget::init(CommandsHandler::exec);
        TabsWidget::init(PageWidget::display);

        // Opening base window
        Commands::open_in_new_tab("https://duckduckgo.com");

        // Setup complete, now everything is done after an user command
        InputHandler::wait_and_read();
    }

    void free()
    {
        // helpers freeing
        PageLoader::free();
        InputHandler::free();
        CommandsHandler::free();

        // widgets freeing
        PageWidget::free();
        CommandWidget::free();
        TabsWidget::free();

        // ncurses closing
        endwin();
    }


}
