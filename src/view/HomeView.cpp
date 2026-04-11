
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

  // Nowy panel z dwoma podpanelami: lewy i prawy
  wxPanel *newPanel = new wxPanel(this, wxID_ANY);
  newPanel->SetBackgroundColour(*wxBLUE);
  wxBoxSizer *newPanelSizer = new wxBoxSizer(wxHORIZONTAL);

  // Lewy panel
  wxPanel *leftPanel = new wxPanel(newPanel, wxID_ANY);
  leftPanel->SetBackgroundColour(*wxLIGHT_GREY);
  wxBoxSizer *leftSizer = new wxBoxSizer(wxVERTICAL);
  wxStaticText *newText = new wxStaticText(leftPanel, wxID_ANY, "Nowy panel w home!");
  leftSizer->Add(newText, 0, wxALL | wxALIGN_CENTER, 10);
  leftPanel->SetSizer(leftSizer);
  leftPanel->SetBackgroundColour(*wxYELLOW);
  wxButton *newCarButton = new wxButton(leftPanel, wxID_ANY, "New Car", wxDefaultPosition, wxSize(80, -1));

  // Prawy panel
  wxPanel *rightPanel = new wxPanel(newPanel, wxID_ANY);
  rightPanel->SetBackgroundColour(*wxLIGHT_GREY);
  rightPanel->SetBackgroundColour(*wxGREEN);
  wxBoxSizer *rightSizer = new wxBoxSizer(wxVERTICAL);
  rightSizer->Add(newCarButton, 0, wxALL | wxALIGN_CENTER, 10);
  rightPanel->SetSizer(rightSizer);

  newPanelSizer->Add(leftPanel, 1, wxEXPAND | wxALL, 5);
  newPanelSizer->Add(rightPanel, 1, wxEXPAND | wxALL, 5);
  newPanel->SetSizer(newPanelSizer);
  mainSizer->Add(newPanel, 1, wxEXPAND | wxALL, 5);

  this->SetSizer(mainSizer);
  mainSizer->Fit(this);
}