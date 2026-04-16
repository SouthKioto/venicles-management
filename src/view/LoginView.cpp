#include "../include/view/LoginView.hpp"
#include "../include/classes/Router.hpp"

#include <wx/stattext.h>
#include <wx/valtext.h>

LoginView::LoginView(wxWindow *window, Router *router)
    : wxPanel(window), router(router) {

  // WARNING: utworzenie głównego kontenera
  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

  // Osobny panel formularza pozwala latwo wycentrowac calosc na stronie.
  wxPanel *inputPanel = new wxPanel(this);
  wxBoxSizer *inputSizer = new wxBoxSizer(wxVERTICAL);

  // WARNING: utworzenie konetenra z loginem
  wxBoxSizer *loginRow = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *labelLogin = new wxStaticText(inputPanel, wxID_ANY, "Login");
  wxTextValidator loginValidator(wxFILTER_ALPHANUMERIC);
  login = new wxTextCtrl(inputPanel, wxID_ANY, "", wxDefaultPosition,
                         wxSize(150, 25), 0, loginValidator);

  // WARNING: dodawanie elementów interfejsu do kontenera
  loginRow->Add(labelLogin, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  loginRow->Add(login, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

  inputSizer->Add(loginRow, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

  // WARNING: utworzenie konetenra z haslem
  wxBoxSizer *passRow = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *labelPass = new wxStaticText(inputPanel, wxID_ANY, "Password");

  pass = new wxTextCtrl(inputPanel, wxID_ANY, "", wxDefaultPosition,
                        wxSize(150, 25), wxTE_PASSWORD);

  // WARNING: dodawanie elementów interfejsu do kontenera
  passRow->Add(labelPass, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  passRow->Add(pass, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

  inputSizer->Add(passRow, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

  submit = new wxButton(inputPanel, wxID_ANY, "Log in");
  inputSizer->Add(submit, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 15);

  registerButton =
      new wxButton(inputPanel, wxID_ANY, "Don't have an account? Register");
  inputSizer->Add(registerButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 15);

  inputPanel->SetSizer(inputSizer);
  inputSizer->Fit(inputPanel);

  mainSizer->AddStretchSpacer(1);
  mainSizer->Add(inputPanel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
  mainSizer->AddStretchSpacer(1);

  registerButton->Bind(wxEVT_BUTTON, [this](wxCommandEvent &) {
    if (this->router != nullptr) {
      this->router->navigate("register");
    }
  });

  // WARNING: dodanie układu do strony
  this->SetSizer(mainSizer);
  mainSizer->SetSizeHints(this);
}

LoginView::~LoginView() {
  // wxWidgets sam czysci dzieci, wiec nie trzeba nic usuwac w destruktorze
}
