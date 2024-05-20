#include <gtkmm.h>
#include <gtk-layer-shell.h>
#include <toml++/toml.hpp>

#include <string>
#include <iostream>

#include "mw-menu.h"

using namespace std;
using namespace Glib;
using namespace Gtk;
using namespace MW;

MyWayMenu::MyWayMenu(RefPtr<Application> app) {
    optional<string> labelStr;
    toml::table tbl;

    this->app = app;

    gtk_layer_init_for_window(gobj());
    gtk_layer_set_layer(gobj(), GTK_LAYER_SHELL_LAYER_TOP);
    gtk_layer_set_anchor(gobj(), GTK_LAYER_SHELL_EDGE_TOP, TRUE);
    gtk_layer_set_anchor(gobj(), GTK_LAYER_SHELL_EDGE_RIGHT, TRUE);
    
    try {
        tbl = toml::parse_file("config/example.toml");
        labelStr = tbl["test"]["label"].value<string>();
    } catch (...) {
        cout << "Couldn't parse file." << endl;
        this->app->quit();
    }
    label1.set_text(labelStr.value_or("Couldn't get the TOML :("));
    add(label1);

    set_title("MyWay Menu");
    show_all();
}
