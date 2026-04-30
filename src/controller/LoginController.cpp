#include "../include/controller/LoginController.hpp"
#include "../../include/database/Database.hpp"
#include "../include/additionalScripts/Validator.hpp"
#include "../include/classes/Router.hpp"
#include "../include/classes/Session.hpp"
#include "../include/classes/User.hpp"
#include "../include/view/MainView.hpp"
#include <iostream>

LoginController::LoginController(LoginModel *model, LoginView *view,
                                 Router *router, Database *database,
                                 Logger *logger, Validator *validator,
                                 MainView *mainView)
    : _model(model), _view(view), router(router), database(database),
      logger(logger), validator(validator), mainview(mainView) {

  _view->logInBtn->Bind(wxEVT_BUTTON, &LoginController::OnSubmitClicked, this);
  _view->registerBtn->Bind(wxEVT_BUTTON, &LoginController::OnRegisterClicked,
                           this);
}

LoginController::~LoginController() {}

void LoginController::OnRegisterClicked(wxCommandEvent &event) {
  router->navigate("register");
}

void LoginController::OnSubmitClicked(wxCommandEvent &event) {
  std::vector<std::string> errors;

  User user;
  errors.clear();

  if (validator->checkEmpty((std::string)_view->getEmailValue()) ||
      validator->checkEmpty((std::string)_view->getPasswordValue()) ||
      !validator->validateEmail((std::string)_view->getEmailValue()) ||
      !_model->checkUserExist((std::string)_view->getEmailValue()) ||
      !_model->checkPassword((std::string)_view->getPasswordValue(),
                             (std::string)_view->getEmailValue()) ||
      !_model->returnUserData((std::string)_view->getEmailValue())
           .has_value()) {

    errors = validator->getErrors();
    auto modelErrors = _model->getErrors();
    errors.insert(errors.end(), modelErrors.begin(), modelErrors.end());
    _view->setErrors(errors);

    return;
  }

  auto userData = _model->returnUserData((std::string)_view->getEmailValue());
  user = userData.value();

  std::string email = user.getEmail();
  Session::getInstance().login(&user);

  mainview->initViews();
}
