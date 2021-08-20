#include "controller.hpp"
#include <cassert>
#include "model/document_loader.hpp"
#include "widgets/tabs.hpp"
#include "widgets/page.hpp"
#include "widgets/command.hpp"
#include "input_handler.hpp"
#include "commands/open.hpp"
#include "commands/handler.hpp"
#include "config/manager.hpp"
#include "config/general.hpp"
#include "config/shortcuts.hpp"

Controller *Controller::instance = nullptr;
// helpers
DocumentLoader *Controller::document_loader = nullptr;
InputHandler *Controller::input_handler = nullptr;
Commands::Handler *Controller::commands_handler = nullptr;
// widgets
Widgets::Page *Controller::page_widget = nullptr;
Widgets::Command *Controller::command_widget = nullptr;
Widgets::Tabs *Controller::tabs_widget = nullptr;

bool Controller::should_quit = false;



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
    Commands::open_in_new_tab(Helpers::HttpRequest{Config::general->get_welcome_url()});
}

Controller::~Controller()
{
    delete document_loader;

    // widgets freeing
    delete page_widget;
    delete command_widget;
    delete tabs_widget;

    // helpers freeing
    delete input_handler;
    delete commands_handler;

    // ncurses closing
    endwin();

    Config::free();
}

void Controller::pause()
{
    tabs_widget->set_refresh_policy(false);
    page_widget->set_refresh_policy(false);
    command_widget->set_refresh_policy(false);

    endwin();
}

void Controller::unpause()
{
    initscr();
    
    tabs_widget->set_refresh_policy(true);
    page_widget->set_refresh_policy(true);
    command_widget->set_refresh_policy(true);

    tabs_widget->refresh_display();
    page_widget->refresh_display();
    command_widget->clear();
}

void Controller::quit_when_possible()
{
    should_quit = true;
}

void Controller::wait_and_handle_input()
{
    while (!should_quit) {
        // Here we only handle shortcuts (some redirect to the widgets)
        const uint16_t c = input_handler->get_input();
        const std::string *command = Config::shortcuts->get_command(c);
        if (command)
            exec(*command);
    }
}

void Controller::print_message(const std::string &message)
{
    command_widget->print_message(message);
}

int Controller::exec(const std::string &command)
{
    return commands_handler->exec(command);
}
