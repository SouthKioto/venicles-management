#ifndef LOGIN_CONTROLLER_HPP
#define LOGIN_CONTROLLER_HPP

#include "../include/model/LoginModel.hpp"
#include "../include/view/LoginView.hpp"
#include <wx/event.h> // WARNING: bindowanie zdarzen (onclick ect)

class Router;
class Database;
class Logger;
class Validator;

class LoginController {

private:
  LoginModel *_model;
  LoginView *_view;

  void OnSubmitClicked(wxCommandEvent &event);
  void OnRegisterClicked(wxCommandEvent &event);

public:
  Router *router;
  Database *database;
  Logger *logger;
  Validator *validator;

  LoginController(LoginModel *model, LoginView *view, Router *router,
                  Database *database, Logger *logger, Validator *validator);
  ~LoginController();
};

#endif // !LOGIN_CONTROLLER_HPP
