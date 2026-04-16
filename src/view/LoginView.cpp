#include "../include/view/LoginView.hpp"

#include <wx/stattext.h>

LoginView::LoginView(wxWindow *window, Router *router) : wxPanel(window) {

  // WARNING: utworzenie głównego kontenera
  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

  // WARNING: utworzenie konetenra z imieniem
  wxBoxSizer *nameRow = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *labelName = new wxStaticText(this, wxID_ANY, "Imie");

  name = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(150, 25));

  // WARNING: dodawanie elementów interfejsu do kontenera
  nameRow->Add(labelName, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  nameRow->Add(name, 1, wxALL | wxEXPAND, 5);

  mainSizer->Add(nameRow, 0, wxEXPAND | wxALL, 5);

  // WARNING: utworzenie konetenra z imieniem
  wxBoxSizer *surnameRow = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *labelSurname = new wxStaticText(this, wxID_ANY, "Nazwisko");

  surname =
      new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(150, 25));

  // WARNING: dodawanie elementów interfejsu do kontenera
  surnameRow->Add(labelSurname, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  surnameRow->Add(surname, 1, wxALL | wxEXPAND, 5);

  mainSizer->Add(surnameRow, 0, wxEXPAND | wxALL, 5);

  submit = new wxButton(this, wxID_ANY, "Zatwierdz");
  mainSizer->Add(submit, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 15);

  changePage = new wxButton(this, wxID_ANY, "Zmien na main");
  mainSizer->Add(changePage, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 15);

  // WARNING: dodanie układu do strony
  this->SetSizer(mainSizer);
  mainSizer->Fit(this);
}

LoginView::~LoginView() {
  // wxWidgets sam czysci dzieci, wiec nie trzeba nic usuwac w destruktorze
}
