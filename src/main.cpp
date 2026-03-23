#include "../include/additionalScripts/Logger.hpp"
#include "../include/controller/LoginController.hpp"
#include "../include/model/LoginModel.hpp"
#include "../include/view/LoginView.hpp"
#include <wx/wx.h>

class VenicleManagement : public wxApp {
private:
  LoginController *_controller = nullptr;

public:
  virtual bool OnInit() override {
    Logger logger("mainlog.log");

    LoginModel *loginModel = new LoginModel();
    LoginView *loginView = new LoginView();

    loginView->Show();
    logger.log(INFO, "Start Aplikacji");

    _controller = new LoginController(loginModel, loginView);

    return true;
  }

  virtual int OnExit() override {
    if (_controller)
      delete _controller;
    return 0;
  }
};

wxIMPLEMENT_APP(VenicleManagement);
