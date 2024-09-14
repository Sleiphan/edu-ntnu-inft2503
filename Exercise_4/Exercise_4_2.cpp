#include <gtkmm.h>

class Window : public Gtk::Window
{
public:
  Gtk::Box box;
  Gtk::Label first_name_label;
  Gtk::Entry first_name;
  Gtk::Label last_name_label;
  Gtk::Entry last_name;
  Gtk::Button button;
  Gtk::Label full_name;

  Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL)
  {
    this->set_title("Øving 4 ;P");

    button.set_label("Combine names");
    button.set_sensitive(false);

    first_name_label.set_text("First name");
    last_name_label.set_text("Last name");

    box.pack_start(first_name_label);
    box.pack_start(first_name);
    box.pack_start(last_name_label);
    box.pack_start(last_name);
    box.pack_start(button);
    box.pack_start(full_name);

    add(box);   // Add vbox to window
    show_all(); // Show all widgets

    first_name.signal_changed().connect([this]()
                                        { entry_update(); });

    last_name.signal_changed().connect([this]()
                                       { entry_update(); });

    button.signal_clicked().connect([this]()
                                    { button_click(); });
  }

private:
  bool entries_populated()
  {
    return first_name.get_text().length() > 0 && last_name.get_text().length() > 0;
  }

  void entry_update()
  {
    button.set_sensitive(entries_populated());
  }

  void button_click()
  {
    std::string full_name_str;
    full_name_str.append(first_name.get_text());
    full_name_str.append(" ");
    full_name_str.append(last_name.get_text());

    full_name.set_text("Combined name: " + full_name_str);
  }
};

int main()
{
  auto app = Gtk::Application::create();
  Window window;
  return app->run(window);
}
