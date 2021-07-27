#include <cassert>
#include "controller.hpp"
#include "model/document_loader.hpp"
#include "widgets/tabs.hpp"
#include "widgets/page.hpp"
#include "widgets/command.hpp"
#include "input_handler.hpp"
#include "commands/open.hpp"
#include "commands/handler.hpp"
#include "config/manager.hpp"
#include "config/general.hpp"

Controller *Controller::instance = nullptr;
// helpers
DocumentLoader *Controller::document_loader = nullptr;
InputHandler *Controller::input_handler = nullptr;
Commands::Handler *Controller::commands_handler = nullptr;
// widgets
Widgets::Page *Controller::page_widget = nullptr;
Widgets::Command *Controller::command_widget = nullptr;
Widgets::Tabs *Controller::tabs_widget = nullptr;



Controller::Controller()
{
    // Controller is a Singleton (the only one)
    assert(!instance);
    instance = this;

    Config::load();

    // ncurses init
    initscr();

    // helpers init
    document_loader = new DocumentLoader();
    input_handler = new InputHandler();
    commands_handler = new Commands::Handler(print_message);

    // widgets init
    page_widget = new Widgets::Page();
    command_widget = new Widgets::Command(exec);
    tabs_widget = new Widgets::Tabs();

    // Opening base window
    Commands::open_in_new_tab(Config::general->get_welcome_url());

    // Setup complete, now everything is done after an user command
    input_handler->wait_and_read(exec);
}

Controller::~Controller()
{
    // widgets freeing
    delete page_widget;
    delete command_widget;
    delete tabs_widget;

    // helpers freeing
    delete document_loader;
    delete input_handler;
    delete commands_handler;

    // ncurses closing
    endwin();

    Config::free();
}


void Controller::print_message(const std::string &message)
{
    command_widget->print_message(message);
}

int Controller::exec(const std::string &command)
{
    return commands_handler->exec(command);
}
