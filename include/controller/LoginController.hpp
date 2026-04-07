#ifndef LOGIN_CONTROLLER_HPP
#define LOGIN_CONTROLLER_HPP

#include "../model/RegistrationModel.hpp"
#include "../view/LoginView.hpp"
#include <wx/event.h> // WARNING: bindowanie zdarzen (onclick ect)

class Router;

class LoginController {

private:
  RegistrationModel *_model;
  LoginView *_view;

  // WARNING: callback, po wykonaniu przycisku
  void OnSubmitClicked(wxCommandEvent &event);
  void OnChangePageClicked(wxCommandEvent &event);

public:
  Router *router;
  LoginController(RegistrationModel *model, LoginView *view, Router *router);
  ~LoginController();
};

#endif // !LOGIN_CONTROLLER_HPP
