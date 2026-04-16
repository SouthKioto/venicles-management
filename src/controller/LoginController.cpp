#include "../include/controller/LoginController.hpp"
#include "../../include/database/Database.hpp"
#include "../include/classes/Router.hpp"
#include "../include/classes/User.hpp"
#include "../include/view/MainView.hpp"
#include <iostream>

LoginController::LoginController(LoginModel *model, LoginView *view,
                                 Router *router)
    : _model(model), _view(view), router(router) {

  _view->changePage->Bind(wxEVT_BUTTON, &LoginController::OnChangePageClicked,
                          this);

  _view->submit->Bind(wxEVT_BUTTON, &LoginController::OnSubmitClicked, this);
}

LoginController::~LoginController() {}

void LoginController::OnSubmitClicked(wxCommandEvent &event) {
  std::vector<std::string> errors;
  errors.clear();

  // INFO: dane trestowe bede zmienial jak dostane pelny formularz z widoku
  User user("Jan", "Kowalski", "jkowalski@example.com", "123");

  _model->setUserData(&user).checkPassword();

  errors = _model->getErrors();

  // WARNING:
  // if(!errors.empty() {
  //  przekazanie do widoku errorow poprzez
  //  _view->setErrors(errors)
  // }

  if (errors.empty() && _model->getLoginFlag()) {
    // zmiana widoku
    router->navigate("home");
  }
}

void LoginController::OnChangePageClicked(wxCommandEvent &event) {
  // this->router->navigate("home");
}
