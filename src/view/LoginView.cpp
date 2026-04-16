#include "../include/view/LoginView.hpp"

#include <wx/stattext.h>

LoginView::LoginView(wxWindow *window, Router *router) : wxPanel(window) {

  // WARNING: utworzenie głównego kontenera
  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

  // Create separate panel for inputs
  wxPanel *inputPanel = new wxPanel(this);
  wxBoxSizer *inputSizer = new wxBoxSizer(wxVERTICAL);

  // WARNING: utworzenie konetenra z imieniem
  wxBoxSizer *nameRow = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *labelName = new wxStaticText(inputPanel, wxID_ANY, "Name");

  name = new wxTextCtrl(inputPanel, wxID_ANY, "", wxDefaultPosition, wxSize(150, 25));

  // WARNING: dodawanie elementów interfejsu do kontenera
  nameRow->Add(labelName, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  nameRow->Add(name, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

  inputSizer->Add(nameRow, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

  // WARNING: utworzenie konetenra z imieniem
  wxBoxSizer *surnameRow = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *labelSurname = new wxStaticText(inputPanel, wxID_ANY, "Surname");

  surname =
      new wxTextCtrl(inputPanel, wxID_ANY, "", wxDefaultPosition, wxSize(150, 25));


  // WARNING: dodawanie elementów interfejsu do kontenera
  surnameRow->Add(labelSurname, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  surnameRow->Add(surname, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

  inputSizer->Add(surnameRow, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

  submit = new wxButton(inputPanel, wxID_ANY, "Submit");
  inputSizer->Add(submit, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 15);

  register_button = new wxButton(inputPanel, wxID_ANY, "Register");
  inputSizer->Add(register_button, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

  inputPanel->SetSizer(inputSizer);
  inputSizer->Fit(inputPanel);

  // Add the input panel to main sizer, centered horizontally
  mainSizer->AddStretchSpacer(1);
  mainSizer->Add(inputPanel, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 10);
  mainSizer->AddStretchSpacer(1);

  // WARNING: dodanie układu do strony
  this->SetSizer(mainSizer);
  mainSizer->SetSizeHints(this);
}


LoginView::~LoginView() {
  // wxWidgets sam czysci dzieci, wiec nie trzeba nic usuwac w destruktorze
}