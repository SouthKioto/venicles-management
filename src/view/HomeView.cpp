
#include "../include/view/HomeView.hpp"

HomeView::HomeView(wxWindow *window, Router *router) : wxPanel(window) {
  SetMinSize(wxSize(1920, 1080));
  SetSize(wxSize(1920, 1080));
  SetBackgroundColour(*wxRED);

  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
  wxPanel *headerPanel = new wxPanel(this, wxID_ANY);
  wxBoxSizer *headerSizer = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *titleRow = new wxBoxSizer(wxHORIZONTAL);

  wxStaticText *labelTitle =
      new wxStaticText(headerPanel, wxID_ANY, "Venicle Management App");

  changePage = new wxButton(headerPanel, wxID_ANY, "Logout", wxDefaultPosition,
                            wxSize(80, -1));

  titleRow->Add(labelTitle, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  titleRow->AddStretchSpacer();
  titleRow->Add(changePage, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  headerSizer->Add(titleRow, 1, wxEXPAND | wxALL, 5);
  headerPanel->SetSizer(headerSizer);

  mainSizer->Add(headerPanel, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 5);

  wxPanel *newPanel = new wxPanel(this, wxID_ANY);
  newPanel->SetBackgroundColour(*wxBLUE);
  wxBoxSizer *newPanelSizer = new wxBoxSizer(wxVERTICAL);
  wxStaticText *newText =
      new wxStaticText(newPanel, wxID_ANY, "New panel on the home page!");
  newPanelSizer->Add(newText, 0, wxALL | wxALIGN_CENTER, 10);
  newPanel->SetSizer(newPanelSizer);
  mainSizer->Add(newPanel, 9, wxEXPAND | wxALL, 5);

  this->SetSizer(mainSizer);
  this->Layout();
}
