#include "../include/view/MainView.hpp"
#include <wx/wx.h>

class VenicleManagement : public wxApp {

public:
  virtual bool OnInit() override {
    MainView *mainView = new MainView();
    mainView->Show();

    return true;
  }
};

wxIMPLEMENT_APP(VenicleManagement);
