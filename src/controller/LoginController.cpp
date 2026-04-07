#include "../../include/controller/LoginController.hpp"
#include "../../include/classes/Router.hpp"
#include <iostream>

LoginController::LoginController(RegistrationModel *model, LoginView *view,
                                 Router *router)
    : _model(model), _view(view), router(router) {
  _view->submit->Bind(wxEVT_BUTTON, &LoginController::OnSubmitClicked,
                      this);
  _view->changePage->Bind(wxEVT_BUTTON, &LoginController::OnChangePageClicked,
                          this);
}

LoginController::~LoginController() {}

void LoginController::OnSubmitClicked(wxCommandEvent &event) {
  wxMessageBox("Rejestracja / logowanie jest obecnie w szkielecie.", "Informacja",
               wxICON_INFORMATION | wxOK);
  this->router->navigate("home");
}

void LoginController::OnChangePageClicked(wxCommandEvent &event) {
  this->router->navigate("home");
}
