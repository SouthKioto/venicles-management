#include "../include/controller/LoginController.hpp"
#include "../../include/database/Database.hpp"
#include "../include/classes/Router.hpp"
#include "../include/classes/User.hpp"
#include "../include/view/MainView.hpp"
#include <iostream>

LoginController::LoginController(LoginModel *model, LoginView *view,
                                 Router *router)
    : _model(model), _view(view), router(router) {
  _view->submit->Bind(wxEVT_BUTTON, &LoginController::OnSubmitClicked,
                      this);
  _view->registerButton->Bind(wxEVT_BUTTON,
                              &LoginController::OnChangePageClicked, this);
}

LoginController::~LoginController() {}

// INFO: zakomentowane w celach pozniejszego wykorzystania
/*void LoginController::OnSubmitClicked(wxCommandEvent &event) {
  // WARNING: pobranie prywantych zmiennych name i surname
  wxString name = _view->getNameValue().ToStdString();
  wxString surname = _view->getSurnameValue().ToStdString();

  std::string email = "testowy@test.com";
  std::string pass = "123";
  int age = 50;

  User *newUser = new User(name, surname, email, pass, age);

  Database db("users.json");
  db.writeInto(*newUser);

  _model->setUser(newUser);
}*/

void LoginController::OnSubmitClicked(wxCommandEvent &event) {
  wxString login = _view->getLoginValue();
  wxString pass = _view->getPassValue();

  if (login.IsEmpty() || pass.IsEmpty()) {
    wxMessageBox("Please fill in both fields.", "Login Error",
                 wxOK | wxICON_ERROR, _view);
    return;
  }

  User *loggedUser = new User(0, login.ToStdString(), "",
                              "unknown@example.com", pass.ToStdString(),
                              false);
  _model->setUser(loggedUser);

  wxMessageBox("Logged in user: " + login, "Login", wxOK | wxICON_INFORMATION,
               _view);
  this->router->navigate("home");
}

void LoginController::OnChangePageClicked(wxCommandEvent &event) {
  this->router->navigate("register");
}
