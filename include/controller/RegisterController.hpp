#ifndef REGISTER_CONTROLLER_HPP
#define REGISTER_CONTROLLER_HPP

#include "../include/model/RegisterModel.hpp"
#include "../include/view/RegisterView.hpp"
#include <wx/event.h>

class Router;
class Database;
class Logger;
class Validator;

class RegisterController {
private:
  RegisterModel *_model;
  RegisterView *_view;

  void OnRegisterClicked(wxCommandEvent &event);
  void OnBackClicked(wxCommandEvent &event);

public:
  Router *router;
  Database *database;
  Logger *logger;
  Validator *validator;

  RegisterController(RegisterModel *model, RegisterView *view, Router *router,
                     Database *database, Logger *logger, Validator *validator);
  ~RegisterController();
};

#endif // !REGISTER_CONTROLLER_HPP
