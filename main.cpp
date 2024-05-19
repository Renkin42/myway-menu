#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class MyWayMenu : public Window {
public:
    MyWayMenu() {
        add(scrolledWindow);
        scrolledWindow.add(fixed);

        label1.set_text("Hello, World!");
        fixed.add(label1);
        fixed.move(label1, 5, 100);

        set_title("MyWay Menu");
        resize(300, 300);
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
