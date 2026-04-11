#include "../include/controller/VehicleController.hpp"
#include "../include/classes/Router.hpp"

VehicleController::VehicleController(VehicleModel *model, VehicleView *view,
                                     Router *router)
    : _model(model), _view(view), router(router) {
  _view->submit->Bind(wxEVT_BUTTON, &VehicleController::OnSubmitClicked, this);
  _view->edit->Bind(wxEVT_BUTTON, &VehicleController::OnEditClicked, this);
  _view->delete_->Bind(wxEVT_BUTTON, &VehicleController::OnDeleteClicked, this);
  _view->changePage->Bind(wxEVT_BUTTON, &VehicleController::OnChangePageClicked,
                          this);
}

VehicleController::~VehicleController() {}

void VehicleController::OnSubmitClicked(wxCommandEvent &event) {
  // Pobierz dane z formularza
  std::string make = std::string(_view->getMakeValue().mb_str());
  std::string modelStr = std::string(_view->getModelValue().mb_str());
  int year = _view->getYearValue();
  std::string color = std::string(_view->getColorValue().mb_str());
  std::string licensePlate = std::string(_view->getLicensePlateValue().mb_str());
  std::string vin = std::string(_view->getVinValue().mb_str());
  std::string owner = std::string(_view->getOwnerValue().mb_str());

  // Utwórz nowy pojazd
  Vehicle *newVehicle =
      new Vehicle(make, modelStr, year, color, licensePlate, vin, owner);
  _model->setVehicle(newVehicle);

  // Dodaj do listy
  wxString vehicleString = wxString::Format(
      "%s %s (%d) - %s", make.c_str(), modelStr.c_str(), year, owner.c_str());
  _view->addVehicleToList(vehicleString);

  // Wyczyść formularz
  _view->clearForm();
}

void VehicleController::OnEditClicked(wxCommandEvent &event) {
  int selection = _view->getSelectedVehicle();
  if (selection != wxNOT_FOUND) {
    // TODO: Implement vehicle editing logic
  }
}

void VehicleController::OnDeleteClicked(wxCommandEvent &event) {
  int selection = _view->getSelectedVehicle();
  if (selection != wxNOT_FOUND) {
    // TODO: Implement vehicle deletion logic
  }
}

void VehicleController::OnChangePageClicked(wxCommandEvent &event) {
  if (router != nullptr) {
    router->navigate("home");
  }
}

void VehicleController::OnVehicleSelected(wxCommandEvent &event) {
  // TODO: Load vehicle data into form
}
