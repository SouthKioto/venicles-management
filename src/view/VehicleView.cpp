#include "../include/view/VehicleView.hpp"
#include "../include/classes/Router.hpp"

VehicleView::VehicleView(wxWindow *window, Router *router)
    : wxPanel(window), router(router) {
  wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

  // Title
  wxStaticText *title = new wxStaticText(this, wxID_ANY, "Rejestracja Pojazdu");
  wxFont titleFont = title->GetFont();
  titleFont.SetPointSize(16);
  titleFont.MakeBold();
  title->SetFont(titleFont);
  mainSizer->Add(title, 0, wxALL | wxCENTRE, 10);

  // Form panel
  wxPanel *formPanel = new wxPanel(this);
  wxBoxSizer *formSizer = new wxBoxSizer(wxVERTICAL);

  // Make
  wxBoxSizer *makeSizer = new wxBoxSizer(wxHORIZONTAL);
  makeSizer->Add(new wxStaticText(formPanel, wxID_ANY, "Marka:"), 0,
                 wxALL | wxALIGN_CENTER_VERTICAL, 5);
  make = new wxTextCtrl(formPanel, wxID_ANY);
  makeSizer->Add(make, 1, wxALL, 5);
  formSizer->Add(makeSizer, 0, wxEXPAND | wxALL, 5);

  // Model
  wxBoxSizer *modelSizer = new wxBoxSizer(wxHORIZONTAL);
  modelSizer->Add(new wxStaticText(formPanel, wxID_ANY, "Model:"), 0,
                  wxALL | wxALIGN_CENTER_VERTICAL, 5);
  model = new wxTextCtrl(formPanel, wxID_ANY);
  modelSizer->Add(model, 1, wxALL, 5);
  formSizer->Add(modelSizer, 0, wxEXPAND | wxALL, 5);

  // Color
  wxBoxSizer *colorSizer = new wxBoxSizer(wxHORIZONTAL);
  colorSizer->Add(new wxStaticText(formPanel, wxID_ANY, "Kolor:"), 0,
                  wxALL | wxALIGN_CENTER_VERTICAL, 5);
  color = new wxTextCtrl(formPanel, wxID_ANY);
  colorSizer->Add(color, 1, wxALL, 5);
  formSizer->Add(colorSizer, 0, wxEXPAND | wxALL, 5);

  // License Plate
  wxBoxSizer *licensePlateSizer = new wxBoxSizer(wxHORIZONTAL);
  licensePlateSizer->Add(new wxStaticText(formPanel, wxID_ANY, "Tablica:"), 0,
                         wxALL | wxALIGN_CENTER_VERTICAL, 5);
  licensePlate = new wxTextCtrl(formPanel, wxID_ANY);
  licensePlateSizer->Add(licensePlate, 1, wxALL, 5);
  formSizer->Add(licensePlateSizer, 0, wxEXPAND | wxALL, 5);

  // VIN
  wxBoxSizer *vinSizer = new wxBoxSizer(wxHORIZONTAL);
  vinSizer->Add(new wxStaticText(formPanel, wxID_ANY, "VIN:"), 0,
                wxALL | wxALIGN_CENTER_VERTICAL, 5);
  vin = new wxTextCtrl(formPanel, wxID_ANY);
  vinSizer->Add(vin, 1, wxALL, 5);
  formSizer->Add(vinSizer, 0, wxEXPAND | wxALL, 5);

  // Owner
  wxBoxSizer *ownerSizer = new wxBoxSizer(wxHORIZONTAL);
  ownerSizer->Add(new wxStaticText(formPanel, wxID_ANY, "Właściciel:"), 0,
                  wxALL | wxALIGN_CENTER_VERTICAL, 5);
  owner = new wxTextCtrl(formPanel, wxID_ANY);
  ownerSizer->Add(owner, 1, wxALL, 5);
  formSizer->Add(ownerSizer, 0, wxEXPAND | wxALL, 5);

  formPanel->SetSizer(formSizer);
  mainSizer->Add(formPanel, 0, wxEXPAND | wxALL, 10);

  // Vehicle List
  wxStaticText *listTitle =
      new wxStaticText(this, wxID_ANY, "Lista Pojazdów:");
  mainSizer->Add(listTitle, 0, wxALL, 5);

  vehicleList = new wxListBox(this, wxID_ANY);
  mainSizer->Add(vehicleList, 1, wxEXPAND | wxALL, 5);

  // Buttons
  wxBoxSizer *buttonSizer = new wxBoxSizer(wxHORIZONTAL);

  submit = new wxButton(this, wxID_ANY, "Dodaj");
  edit = new wxButton(this, wxID_ANY, "Edytuj");
  delete_ = new wxButton(this, wxID_ANY, "Usuń");
  changePage = new wxButton(this, wxID_ANY, "Powróć");

  buttonSizer->Add(submit, 0, wxALL, 5);
  buttonSizer->Add(edit, 0, wxALL, 5);
  buttonSizer->Add(delete_, 0, wxALL, 5);
  buttonSizer->Add(changePage, 0, wxALL, 5);

  mainSizer->Add(buttonSizer, 0, wxALL | wxCENTRE, 5);

  SetSizer(mainSizer);
}

VehicleView::~VehicleView() {}

void VehicleView::addVehicleToList(const wxString &vehicle) {
  vehicleList->Append(vehicle);
}

void VehicleView::clearForm() {
  make->SetValue("");
  model->SetValue("");
  color->SetValue("");
  licensePlate->SetValue("");
  vin->SetValue("");
  owner->SetValue("");
}
