#include "../../include/view/LoginView.hpp"

#include <wx/stattext.h>

LoginView::LoginView(wxWindow *window, Router *router) : wxPanel(window) {
  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

  wxStaticText *title = new wxStaticText(this, wxID_ANY,
                                         "Rejestracja / logowanie (szkielet)");
  mainSizer->Add(title, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 15);

  submit = new wxButton(this, wxID_ANY, "Zatwierdź");
  mainSizer->Add(submit, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 15);

  changePage = new wxButton(this, wxID_ANY, "Zmien na main");
  mainSizer->Add(changePage, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 15);

  this->SetSizer(mainSizer);
  mainSizer->Fit(this);
}

LoginView::~LoginView() {
}
