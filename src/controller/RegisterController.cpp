#include "../include/controller/RegisterController.hpp"
#include <vector>
#include <string>

RegisterController::RegisterController(RegisterModel *model, RegisterView *view,
                                       Router *router, Logger *logger,
                                       Validator *validator)
    : _model(model), _view(view), router(router), logger(logger),
      validator(validator) {

  _view->registerBtn->Bind(wxEVT_BUTTON, &RegisterController::OnRegisterClicked, this);
  _view->backBtn->Bind(wxEVT_BUTTON, &RegisterController::OnBackClicked, this);
}

RegisterController::~RegisterController() {}

void RegisterController::OnBackClicked(wxCommandEvent &event) {
  router->navigate("login");
}

void RegisterController::OnRegisterClicked(wxCommandEvent &event) {
  std::string name = _view->getNameValue().ToStdString();
  std::string surname = _view->getSurnameValue().ToStdString();
  std::string email = _view->getEmailValue().ToStdString();
  std::string password = _view->getPasswordValue().ToStdString();
  std::string confirm = _view->getConfirmPasswordValue().ToStdString();

  std::vector<std::string> errors;

  if (validator->checkEmpty(name) || 
      validator->checkEmpty(surname) ||
      validator->checkEmpty(email) || 
      validator->checkEmpty(password) ||
      !validator->validateEmail(email)) {
  } 
  else if (password != confirm) {
      errors.push_back("Passwords do not match.");
  } 
  else {
      _model->checkUserExists(email);
  }

  std::vector<std::string> valErrors = validator->getErrors();
  errors.insert(errors.end(), valErrors.begin(), valErrors.end());
  std::vector<std::string> modelErrors = _model->getErrors();
  errors.insert(errors.end(), modelErrors.begin(), modelErrors.end());

  if (!errors.empty()) {
    _view->setErrors(errors);
    return;
  }

  if (_model->registerUser(name, surname, email, password)) {
    router->navigate("login");
  }
}