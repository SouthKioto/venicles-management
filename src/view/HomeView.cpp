
#include "../include/view/HomeView.hpp"

HomeView::HomeView(wxWindow *window, Router *router) : wxPanel(window) {
  SetBackgroundColour(*wxRED);

  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *titleRow = new wxBoxSizer(wxHORIZONTAL);

  wxStaticText *labelTitle = new wxStaticText(this, wxID_ANY, "Venicle Management App");

  changePage = new wxButton(this, wxID_ANY, "Logout", wxDefaultPosition, wxSize(80, -1));

  titleRow->Add(labelTitle, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  titleRow->AddStretchSpacer();  // Rozciąga przestrzeń między tytułem a przyciskiem
  titleRow->Add(changePage, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

  mainSizer->Add(titleRow, 0, wxEXPAND | wxALL, 5);

  // Nowy panel (bez przycisku)
  wxPanel *newPanel = new wxPanel(this, wxID_ANY);
  newPanel->SetBackgroundColour(*wxBLUE);
  wxBoxSizer *newPanelSizer = new wxBoxSizer(wxVERTICAL);
  wxStaticText *newText = new wxStaticText(newPanel, wxID_ANY, "Nowy panel w home!");
  newPanelSizer->Add(newText, 0, wxALL | wxALIGN_CENTER, 10);
  newPanel->SetSizer(newPanelSizer);
  mainSizer->Add(newPanel, 1, wxEXPAND | wxALL, 5);

  this->SetSizer(mainSizer);
  mainSizer->Fit(this);
}
