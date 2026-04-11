#ifndef VEHICLE_CONTROLLER_HPP
#define VEHICLE_CONTROLLER_HPP

#include "../include/model/VehicleModel.hpp"
#include "../include/view/VehicleView.hpp"
#include <wx/event.h>

class Router;

class VehicleController {

private:
  VehicleModel *_model;
  VehicleView *_view;

  // WARNING: callback, po wykonaniu przycisku
  void OnSubmitClicked(wxCommandEvent &event);
  void OnEditClicked(wxCommandEvent &event);
  void OnDeleteClicked(wxCommandEvent &event);
  void OnChangePageClicked(wxCommandEvent &event);
  void OnVehicleSelected(wxCommandEvent &event);

public:
  Router *router;
  VehicleController(VehicleModel *model, VehicleView *view, Router *router);
  ~VehicleController();
};

#endif // !VEHICLE_CONTROLLER_HPP
