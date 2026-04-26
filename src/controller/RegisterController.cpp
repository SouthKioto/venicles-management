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
  std::string name = (std::string)_view->getNameValue();
  std::string surname = (std::string)_view->getSurnameValue();
  std::string email = (std::string)_view->getEmailValue();
  std::string password = (std::string)_view->getPasswordValue();
  std::string confirm = (std::string)_view->getConfirmPasswordValue();

  std::vector<std::string> errors;

  // basic validation
  if (validator->checkEmpty(name) || validator->checkEmpty(surname) ||
      validator->checkEmpty(email) || validator->checkEmpty(password)) {
    errors.push_back("All fields are required.");
  } else if (password != confirm) {
    errors.push_back("Passwords do not match.");
  } else {
      // logic validation
      validator->validateEmail(email);
      _model->checkUserExists(email);
  }

  errors.insert(errors.end(), validator->getErrors().begin(), validator->getErrors().end());
  auto modelErrors = _model->getErrors();
  errors.insert(errors.end(), modelErrors.begin(), modelErrors.end());

  if (!errors.empty()) {
    _view->setErrors(errors);
    return;
  }

  if (_model->registerUser(name, surname, email, password)) {
    router->navigate("login");
  }
}