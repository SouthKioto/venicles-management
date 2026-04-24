#include "../include/controller/LoginController.hpp"
#include "../../include/database/Database.hpp"
#include "../include/classes/Router.hpp"
#include "../include/classes/User.hpp"
#include "../include/view/MainView.hpp"
#include <iostream>

LoginController::LoginController(LoginModel *model, LoginView *view,
                                 Router *router, Database *database,
                                 Logger *logger)
    : _model(model), _view(view), router(router), database(database),
      logger(logger) {

  _view->submit->Bind(wxEVT_BUTTON, &LoginController::OnSubmitClicked, this);
}

LoginController::~LoginController() {}

void LoginController::OnSubmitClicked(wxCommandEvent &event) {
  bool loginFlag = true;
  std::vector<std::string> errors;

  std::vector<User> userData;
  errors.clear();

  if (_model->checkUserExist(_view->getEmailValue()) ||
      _model->checkPassword(_view->getPasswordValue(),
                            _view->getEmailValue())) {
    logger->log(LogLevel::Error, "Cannot login");
    loginFlag = false;
  }

  errors = _model->getErrors();

  if (_model->returnUserData(_view->getEmailValue()).empty()) {
    logger->log(LogLevel::Error, "Cannot login");

    loginFlag = false;
  }

  if (!errors.empty()) {
    logger->log(LogLevel::Error, "Cannot login");

    loginFlag = false;
  }

  if (!errors.empty()) {
    _view->setErrors(errors);

    loginFlag = false;
  }

  if (loginFlag) {

    // TODO: wymyślic utrzymywanie sesji
    // WARNING: setup sesji usera
    router->navigate("home");
  }
}
