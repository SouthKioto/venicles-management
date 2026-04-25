#include "../include/controller/RegisterController.hpp"
#include "../include/additionalScripts/Validator.hpp"
#include "../include/classes/Router.hpp"

RegisterController::RegisterController(RegisterModel *model, RegisterView *view,
                                       Router *router, Database *database,
                                       Logger *logger, Validator *validator)
    : _model(model), _view(view), router(router), database(database),
      logger(logger), validator(validator) {

  _view->registerBtn->Bind(wxEVT_BUTTON,
                           &RegisterController::OnRegisterClicked, this);
  _view->backBtn->Bind(wxEVT_BUTTON, &RegisterController::OnBackClicked, this);
}

RegisterController::~RegisterController() {}

void RegisterController::OnRegisterClicked(wxCommandEvent &event) {
  std::vector<std::string> errors;
  errors.clear();

  std::string nameVal = (std::string)_view->getNameValue();
  std::string surnameVal = (std::string)_view->getSurnameValue();
  std::string emailVal = (std::string)_view->getEmailValue();
  std::string passwordVal = (std::string)_view->getPasswordValue();
  std::string confirmVal = (std::string)_view->getConfirmPasswordValue();

  if (validator->checkEmpty(nameVal) || validator->checkEmpty(surnameVal) ||
      validator->checkEmpty(emailVal) || validator->checkEmpty(passwordVal) ||
      validator->checkEmpty(confirmVal)) {
    errors = validator->getErrors();
    _view->setErrors(errors);
    return;
  }

  if (!validator->validateEmail(emailVal)) {
    errors = validator->getErrors();
    _view->setErrors(errors);
    return;
  }

  if (passwordVal != confirmVal) {
    errors.push_back("Hasla nie sa identyczne");
    _view->setErrors(errors);
    return;
  }

  if (_model->checkUserExists(emailVal)) {
    errors = _model->getErrors();
    _view->setErrors(errors);
    return;
  }

  if (!_model->registerUser(nameVal, surnameVal, emailVal, passwordVal)) {
    errors = _model->getErrors();
    _view->setErrors(errors);
    return;
  }

  router->navigate("login");
}

void RegisterController::OnBackClicked(wxCommandEvent &event) {
  router->navigate("login");
}
