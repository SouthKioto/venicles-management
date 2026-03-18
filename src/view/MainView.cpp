#include "../../include/view/MainView.hpp"

MainView::MainView()
    : wxFrame(nullptr, wxID_ANY, "Vehicle Management", wxDefaultPosition,
              wxSize(400, 200)) {
  wxPanel *panel = new wxPanel(this);
  wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

  m_text = new wxStaticText(panel, wxID_ANY, "Kliknij przycisk...",
                            wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
  m_button = new wxButton(panel, wxID_ANY, "Powitanie");

  sizer->Add(m_text, 0, wxALL | wxALIGN_CENTER, 20);
  sizer->Add(m_button, 0, wxALL | wxALIGN_CENTER, 10);

  panel->SetSizer(sizer);
}

void MainView::setGreetingText(const std::string &text) {
  m_text->SetLabel(text);
}
