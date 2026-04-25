
#include "../include/view/HomeView.hpp"

HomeView::HomeView(wxWindow *window, Router *router) : wxPanel(window) {
  SetBackgroundColour(wxColour(17, 24, 39));
  SetForegroundColour(wxColour(229, 231, 235));

  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *titleRow = new wxBoxSizer(wxHORIZONTAL);

  wxStaticText *labelTitle = new wxStaticText(this, wxID_ANY, "Home page");
  labelTitle->SetForegroundColour(wxColour(255, 255, 255));

  logoutBtn = new wxButton(this, wxID_ANY, "Wyloguj");
  logoutBtn->SetBackgroundColour(wxColour(55, 65, 81));
  logoutBtn->SetForegroundColour(wxColour(255, 255, 255));
  logoutBtn->SetFont(
      wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

  titleRow->Add(labelTitle, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  titleRow->AddStretchSpacer(1);
  titleRow->Add(logoutBtn, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

  mainSizer->Add(titleRow, 0, wxEXPAND | wxALL, 5);

  // Jeden panel
  wxBoxSizer *panelRow = new wxBoxSizer(wxHORIZONTAL);

  wxPanel *mainPanel = new wxPanel(this, wxID_ANY);
  mainPanel->SetBackgroundColour(wxColour(31, 41, 55));
  wxBoxSizer *panelSizer = new wxBoxSizer(wxVERTICAL);
  wxStaticText *panelTitle =
      new wxStaticText(mainPanel, wxID_ANY, "Panel", wxDefaultPosition,
                       wxDefaultSize, wxALIGN_CENTER);
  panelTitle->SetForegroundColour(wxColour(255, 255, 255));
  panelTitle->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                            wxFONTWEIGHT_BOLD));
  wxStaticText *panelDesc =
      new wxStaticText(mainPanel, wxID_ANY, "Opis panelu",
                       wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
  panelDesc->SetForegroundColour(wxColour(107, 114, 128));
  panelSizer->AddStretchSpacer(1);
  panelSizer->Add(panelTitle, 0, wxEXPAND | wxBOTTOM, 8);
  panelSizer->Add(panelDesc, 0, wxEXPAND);
  panelSizer->AddStretchSpacer(1);
  mainPanel->SetSizer(panelSizer);

  panelRow->Add(mainPanel, 1, wxEXPAND | wxALL, 10);

  mainSizer->Add(panelRow, 1, wxEXPAND | wxLEFT | wxRIGHT | wxBOTTOM, 5);

  this->SetSizer(mainSizer);
  mainSizer->Fit(this);
}
