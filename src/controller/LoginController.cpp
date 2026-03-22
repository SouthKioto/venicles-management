#include "../include/controller/LoginController.hpp"
#include "../include/classes/User.hpp"
#include <iostream>

LoginController::LoginController(LoginModel *model, LoginView *view)
    : _model(model), _view(view) {
  _view->submit->Bind(wxEVT_BUTTON, &LoginController::OnSubmitClicked, this);
}

LoginController::~LoginController() {}

void LoginController::OnSubmitClicked(wxCommandEvent &event) {
  // WARNING: pobranie prywantych zmiennych name i surname
  wxString name = _view->getNameValue().ToStdString();
  wxString surname = _view->getSurnameValue().ToStdString();

  std::string email = "testowy@test.com";
  std::string pass = "123";
  int age = 50;

  User *newUser = new User(name, surname, email, pass, age);

  _model->setUser(newUser);
}
