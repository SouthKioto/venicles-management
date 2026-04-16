#include "../include/view/RegisterView.hpp"

#include <wx/stattext.h>
#include <wx/valtext.h>

RegisterView::RegisterView(wxWindow *window, Router *router) : wxPanel(window) {
  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

  wxStaticText *title = new wxStaticText(this, wxID_ANY, "Register Page");
  mainSizer->Add(title, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 10);

  wxBoxSizer *nameRow = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *labelName = new wxStaticText(this, wxID_ANY, "Name");
  wxTextValidator nameValidator(wxFILTER_ALPHA);
  name = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(150, 25), 0, nameValidator);
  nameRow->Add(labelName, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  nameRow->Add(name, 1, wxALL | wxEXPAND, 5);
  mainSizer->Add(nameRow, 0, wxEXPAND | wxALL, 5);

  wxBoxSizer *surnameRow = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *labelSurname = new wxStaticText(this, wxID_ANY, "Surname");
  wxTextValidator surnameValidator(wxFILTER_ALPHA);
  surname = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(150, 25), 0, surnameValidator);
  surnameRow->Add(labelSurname, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  surnameRow->Add(surname, 1, wxALL | wxEXPAND, 5);
  mainSizer->Add(surnameRow, 0, wxEXPAND | wxALL, 5);

  wxBoxSizer *loginRow = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *labelLogin = new wxStaticText(this, wxID_ANY, "Login");
  login = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition,
                         wxSize(150, 25));
  loginRow->Add(labelLogin, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  loginRow->Add(login, 1, wxALL | wxEXPAND, 5);
  mainSizer->Add(loginRow, 0, wxEXPAND | wxALL, 5);

  wxBoxSizer *passwordRow = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *labelPassword = new wxStaticText(this, wxID_ANY, "Password");
  password = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition,
                            wxSize(150, 25), wxTE_PASSWORD);
  passwordRow->Add(labelPassword, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  passwordRow->Add(password, 1, wxALL | wxEXPAND, 5);
  mainSizer->Add(passwordRow, 0, wxEXPAND | wxALL, 5);

  submit = new wxButton(this, wxID_ANY, "Submit");
  mainSizer->Add(submit, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 15);

  changePage = new wxButton(this, wxID_ANY, "I have an account, log in");
  mainSizer->Add(changePage, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 15);

  this->SetSizer(mainSizer);
  mainSizer->Fit(this);
}

RegisterView::~RegisterView() {
}
