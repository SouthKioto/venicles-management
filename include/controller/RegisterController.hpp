#ifndef REGISTER_CONTROLLER_HPP
#define REGISTER_CONTROLLER_HPP

#include "../include/model/RegisterModel.hpp"
#include "../include/view/RegisterView.hpp"
#include <wx/event.h>

class Router;

class RegisterController {
private:
  RegisterModel *_model;
  RegisterView *_view;

  void OnSubmitClicked(wxCommandEvent &event);
  void OnChangePageClicked(wxCommandEvent &event);

public:
  Router *router;
  RegisterController(RegisterModel *model, RegisterView *view, Router *router);
  ~RegisterController();
};

#endif // !REGISTER_CONTROLLER_HPP
