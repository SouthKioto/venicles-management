#include "../include/controller/GreetingsController.hpp"
#include "model/Greetings.hpp"
#include "view/MainView.hpp"
#include <wx/wx.h>

class MyApp : public wxApp {
public:
  virtual bool OnInit() {
    Greetings *model = new Greetings();
    MainView *view = new MainView();

    new GreetingsController(model, view);

    view->Show(true);
    return true;
  }
};

wxIMPLEMENT_APP(MyApp);
