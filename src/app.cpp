#include "app.hpp"
#include <iostream>
#include <yaml-cpp/yaml.h>
#include "model/document_loader.hpp"
#include "widgets/tabs.hpp"
#include "widgets/page.hpp"
#include "commands/open.hpp"
#include "commands/handler.hpp"
#include "config.hpp"


App::App(const YAML::Node &yaml_config)
    : Vim::App(new Commands::Handler(this), yaml_config)
{
    config = new Config(yaml_config);

    // helpers init
    document_loader = new DocumentLoader(config);

    // widgets init
    page_widget = new Widgets::Page();
    tabs_widget = new Widgets::Tabs();

    // Opening base window
    Commands::open_in_new_tab(this, Helpers::HttpRequest{config->get_welcome_url()});
}

App::~App()
{
    delete document_loader;

    // widgets freeing
    delete page_widget;
    delete tabs_widget;

    // helpers freeing
    delete config;

    // ncurses closing
    endwin();
}

void App::pause()
{
    Vim::App::pause();

    tabs_widget->set_refresh_policy(false);
    page_widget->set_refresh_policy(false);
}

void App::unpause()
{
    tabs_widget->set_refresh_policy(true);
    page_widget->set_refresh_policy(true);

    tabs_widget->refresh_display();
    page_widget->refresh_display();
    
    Vim::App::unpause();
}

Config *App::get_config() {
    return config;
}
DocumentLoader *App::get_document_loader() {
    return document_loader;
}
Widgets::Page *App::get_page_widget() {
    return page_widget;
}
Widgets::Tabs *App::get_tabs_widget() {
    return tabs_widget;
}
