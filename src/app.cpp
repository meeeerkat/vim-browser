#include "app.hpp"
#include <stdlib.h>
#include <yaml-cpp/yaml.h>
#include "model/document_loader.hpp"
#include "widgets/tabs.hpp"
#include "widgets/page.hpp"
#include "widgets/command.hpp"
#include "input_handler.hpp"
#include "commands/open.hpp"
#include "commands/handler.hpp"
#include "browser_config.hpp"


App::App()
    : should_quit(false)
{
    std::string path = std::string(getenv("HOME")) + "/.vim-browser.yaml";
    YAML::Node yaml_config = YAML::LoadFile(path);
    config = new BrowserConfig(yaml_config);

    // ncurses init
    initscr();

    // helpers init
    document_loader = new DocumentLoader(config);
    input_handler = new InputHandler();
    commands_handler = new Commands::Handler();

    // widgets init
    command_widget = new Widgets::Command();
    page_widget = new Widgets::Page();
    tabs_widget = new Widgets::Tabs();

    // Opening base window
    Commands::open_in_new_tab(this, Helpers::HttpRequest{config->get_welcome_url()});
}

App::~App()
{
    delete document_loader;

    // widgets freeing
    delete command_widget;
    delete page_widget;
    delete tabs_widget;

    // helpers freeing
    delete input_handler;
    delete commands_handler;

    // ncurses closing
    endwin();
}

void App::pause()
{
    tabs_widget->set_refresh_policy(false);
    page_widget->set_refresh_policy(false);
    command_widget->set_refresh_policy(false);

    endwin();
}

void App::unpause()
{
    initscr();
    
    tabs_widget->set_refresh_policy(true);
    page_widget->set_refresh_policy(true);
    command_widget->set_refresh_policy(true);

    tabs_widget->refresh_display();
    page_widget->refresh_display();
    command_widget->clear();
}

void App::quit_when_possible()
{
    should_quit = true;
}

void App::wait_and_handle_input()
{
    while (!should_quit) {
        // Here we only handle shortcuts (some redirect to the widgets)
        const uint16_t c = input_handler->get_input();
        const std::string *command = config->get_command_from_shortcut(c);
        if (command)
            exec(*command);
    }
}

int App::exec(const std::string &command)
{
    return commands_handler->exec(this, command);
}

BrowserConfig *App::getConfig() {
    return config;
}
DocumentLoader *App::getDocumentLoader() {
    return document_loader;
}
InputHandler *App::getInputHandler() {
    return input_handler;
}
Widgets::Command *App::getCommandWidget() {
    return command_widget;
}
Widgets::Page *App::getPageWidget() {
    return page_widget;
}
Widgets::Tabs *App::getTabsWidget() {
    return tabs_widget;
}
