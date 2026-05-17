#include "../include/view/UserPageView.hpp"
#include "../include/classes/Session.hpp"

#include <wx/stattext.h>

UserPageView::UserPageView(wxWindow *window) : wxPanel(window) {
  SetBackgroundColour(wxColour(17, 24, 39));
  SetForegroundColour(wxColour(229, 231, 235));

  wxBoxSizer *topSizer = new wxBoxSizer(wxVERTICAL);

  wxScrolledWindow *scrolledWindow = new wxScrolledWindow(this, wxID_ANY);
  scrolledWindow->SetScrollRate(0, 10);

  wxBoxSizer *contentSizer = new wxBoxSizer(wxVERTICAL);

  wxBoxSizer *titleRow = new wxBoxSizer(wxHORIZONTAL);
  wxStaticText *labelTitle = new wxStaticText(scrolledWindow, wxID_ANY,
                                              Session::getInstance().getName());
  labelTitle->SetForegroundColour(wxColour(255, 255, 255));

  backButton = new wxButton(scrolledWindow, wxID_ANY, "Back To Home Page");
  backButton->SetBackgroundColour(wxColour(55, 65, 81));
  backButton->SetForegroundColour(wxColour(255, 255, 255));
  backButton->SetFont(
      wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));

  titleRow->Add(labelTitle, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  titleRow->Add(backButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  contentSizer->Add(titleRow, 0, wxEXPAND | wxALL, 5);

  wxPanel *mainPanel = new wxPanel(scrolledWindow, wxID_ANY);
  mainPanel->SetBackgroundColour(wxColour(31, 41, 55));
  mainPanel->SetMinSize(wxSize(-1, 350));

  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
  wxStaticText *panelTitle =
      new wxStaticText(mainPanel, wxID_ANY, "Panel", wxDefaultPosition,
                       wxDefaultSize, wxALIGN_CENTER);
  panelTitle->SetForegroundColour(wxColour(255, 255, 255));
  mainSizer->AddStretchSpacer(1);
  mainSizer->Add(panelTitle, 0, wxALIGN_CENTER | wxBOTTOM, 8);
  mainSizer->AddStretchSpacer(1);
  mainPanel->SetSizer(mainSizer);

  contentSizer->Add(mainPanel, 0, wxEXPAND | wxALL, 10);

  if (this->isAdmin) {
    wxPanel *adminPanel = new wxPanel(scrolledWindow, wxID_ANY);
    adminPanel->SetBackgroundColour(wxColour(31, 41, 55));
    adminPanel->SetMinSize(wxSize(-1, 150));

    wxBoxSizer *adminSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticText *adminTitle =
        new wxStaticText(adminPanel, wxID_ANY, "Dla admina", wxDefaultPosition,
                         wxDefaultSize, wxALIGN_CENTER);
    adminTitle->SetForegroundColour(wxColour(255, 255, 255));
    adminTitle->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
                               wxFONTWEIGHT_BOLD));

    adminSizer->AddStretchSpacer(1);
    adminSizer->Add(adminTitle, 0, wxALIGN_CENTER);
    adminSizer->AddStretchSpacer(1);
    adminPanel->SetSizer(adminSizer);

    contentSizer->Add(adminPanel, 0, wxEXPAND | wxALL, 10);
  }

  scrolledWindow->SetSizer(contentSizer);
  contentSizer->FitInside(scrolledWindow);

  topSizer->Add(scrolledWindow, 1, wxEXPAND);
  this->SetSizer(topSizer);
}
