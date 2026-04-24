#include "../include/view/LoginView.hpp"
#include <wx/stattext.h>

LoginView::~LoginView() {}

LoginView::LoginView(wxWindow *window, Router *router) : wxPanel(window) {
  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

  mainSizer->AddStretchSpacer(1);

  wxBoxSizer *formSizer = new wxBoxSizer(wxVERTICAL);

  wxBoxSizer *errorRow = new wxBoxSizer(wxHORIZONTAL);

  if (!this->errors.empty()) {
    for (std::string errorMessage : this->errors) {

      wxStaticText *labelError = new wxStaticText(this, wxID_ANY, errorMessage);
      errorRow->Add(labelError, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);
    }
  }

  formSizer->Add(errorRow, 0, wxEXPAND | wxBOTTOM, 10);

  wxBoxSizer *emailRow = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *labelEmail = new wxStaticText(this, wxID_ANY, "Email");
  email =
      new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));

  emailRow->Add(labelEmail, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);
  emailRow->Add(email, 1);

  formSizer->Add(emailRow, 0, wxEXPAND | wxBOTTOM, 10);

  wxBoxSizer *passwordRow = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *labelPassword = new wxStaticText(this, wxID_ANY, "Password");
  password =
      new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));

  passwordRow->Add(labelPassword, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 10);
  passwordRow->Add(password, 1);

  formSizer->Add(passwordRow, 0, wxEXPAND | wxBOTTOM, 20);

  submit = new wxButton(this, wxID_ANY, "Zatwierdź");

  formSizer->Add(submit, 0, wxALIGN_CENTER | wxBOTTOM, 10);

  mainSizer->Add(formSizer, 0, wxALIGN_CENTER);

  mainSizer->AddStretchSpacer(1);

  this->SetSizer(mainSizer);
  mainSizer->Fit(this);
}

void LoginView::setErrors(std::vector<std::string> &errors) {
  this->errors = errors;
}

std::vector<std::string> LoginView::getErrors() const { return this->errors; }
