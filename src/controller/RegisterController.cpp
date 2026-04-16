#include "../include/controller/RegisterController.hpp"
#include "../include/classes/Router.hpp"
#include "../include/classes/User.hpp"
#include <wx/msgdlg.h>

RegisterController::RegisterController(RegisterModel *model, RegisterView *view,
                                       Router *router)
    : _model(model), _view(view), router(router) {
  _view->submit->Bind(wxEVT_BUTTON, &RegisterController::OnSubmitClicked,
                      this);
  _view->changePage->Bind(wxEVT_BUTTON,
                          &RegisterController::OnChangePageClicked, this);
}

RegisterController::~RegisterController() {}

void RegisterController::OnSubmitClicked(wxCommandEvent &event) {
  wxString name = _view->getNameValue();
  wxString surname = _view->getSurnameValue();
  wxString login = _view->getLoginValue();
  wxString password = _view->getPasswordValue();

  if (name.IsEmpty() || surname.IsEmpty() || login.IsEmpty() ||
      password.IsEmpty()) {
    wxMessageBox("Please fill in all fields.", "Registration Error",
                 wxOK | wxICON_ERROR, _view);
    return;
  }

  User *newUser =
      new User(0, name.ToStdString(), surname.ToStdString(),
               login.ToStdString(), password.ToStdString(), false);
  _model->setUser(newUser);

  wxMessageBox("Registration completed.\n" + name + " " + surname,
               "Registration", wxOK | wxICON_INFORMATION, _view);
  this->router->navigate("login");
}

void RegisterController::OnChangePageClicked(wxCommandEvent &event) {
  this->router->navigate("login");
}
