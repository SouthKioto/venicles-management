
#include "../../include/view/HomeView.hpp"

HomeView::HomeView(wxWindow *window, Router *router) : wxPanel(window) {
  SetBackgroundColour(*wxRED);

  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer *titleRow = new wxBoxSizer(wxHORIZONTAL);

  wxStaticText *labelTitle = new wxStaticText(this, wxID_ANY, "Home page");

  changePage = new wxButton(this, wxID_ANY, "Zmien");

  titleRow->Add(labelTitle, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
  titleRow->Add(changePage, 1, wxALL | wxEXPAND, 5);

  mainSizer->Add(titleRow, 0, wxEXPAND | wxALL, 5);

  vehicleList = new wxListBox(this, wxID_ANY);
  mainSizer->Add(vehicleList, 1, wxALL | wxEXPAND, 5);

  this->SetSizer(mainSizer);
  mainSizer->Fit(this);
}

HomeView::~HomeView() {}

void HomeView::setVehicles(const std::vector<Venicle> &vehicles) {
  vehicleList->Clear();
  for (const Venicle &vehicle : vehicles) {
    vehicleList->Append(wxString::Format("%s %s [%s] - %d",
                                        vehicle.getMake(), vehicle.getModel(),
                                        vehicle.getPlate(), vehicle.getYear()));
  }
}
