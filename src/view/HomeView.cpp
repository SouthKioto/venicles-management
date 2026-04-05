
#include "../include/view/HomeView.hpp"

HomeView::HomeView(wxWindow *window, Router *router) : wxPanel(window) {
  SetBackgroundColour(*wxRED);

  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *titleRow = new wxBoxSizer(wxHORIZONTAL);

  wxStaticText *labelTitle = new wxStaticText(this, wxID_ANY, "Home page");

  changePage = new wxButton(this, wxID_ANY, "Zmien");

  titleRow->Add(labelTitle, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  titleRow->Add(changePage, 1, wxALL | wxEXPAND, 5);

  mainSizer->Add(titleRow, 0, wxEXPAND | wxALL, 5);

  this->SetSizer(mainSizer);
  mainSizer->Fit(this);
}
