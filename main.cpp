#include <gtkmm.h>
#include <gtk-layer-shell.h>

#include "mw-menu.h"

using namespace Glib;
using namespace Gtk;
using namespace MW;

int main(int argc, char* argv[]) {
    RefPtr<Application> application = Application::create(argc, argv);
    MyWayMenu menu(application);
    return application->run(menu);
}
