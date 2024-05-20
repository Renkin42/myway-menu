#ifndef MW_MENU_H
#define MW_MENU_H

namespace MW
{
    class MyWayMenu : public Gtk::Window {
        public:
            MyWayMenu(Glib::RefPtr<Gtk::Application>);
        private:
            Glib::RefPtr<Gtk::Application> app;
            Gtk::Label label1;
    };
}

#endif
