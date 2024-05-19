#include <gtkmm.h>
#include <gtk-layer-shell.h>

using namespace Glib;
using namespace Gtk;

class MyWayMenu : public Window {
public:
    MyWayMenu() {
        gtk_layer_init_for_window(gobj());
        gtk_layer_set_layer(gobj(), GTK_LAYER_SHELL_LAYER_TOP);
        gtk_layer_set_anchor(gobj(), GTK_LAYER_SHELL_EDGE_TOP, TRUE);
        gtk_layer_set_anchor(gobj(), GTK_LAYER_SHELL_EDGE_RIGHT, TRUE);

        label1.set_text("Hello, World!");
        add(label1);

        set_title("MyWay Menu");
        show_all();
    }
private:
    Fixed fixed;
    ScrolledWindow scrolledWindow;
    Label label1;
};

int main(int argc, char* argv[]) {
    RefPtr<Application> application = Application::create(argc, argv);
    MyWayMenu menu;
    return application->run(menu);
}
