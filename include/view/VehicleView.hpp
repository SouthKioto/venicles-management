#ifndef VEHICLE_VIEW_HPP
#define VEHICLE_VIEW_HPP
#include <wx/richtext/richtextctrl.h>
#include <wx/spinctrl.h>
#include <wx/wx.h>

class Router;

class VehicleView : public wxPanel {
private:
  wxTextCtrl *make;
  wxTextCtrl *model;
  wxSpinCtrl *year;
  wxTextCtrl *color;
  wxTextCtrl *licensePlate;
  wxTextCtrl *vin;
  wxTextCtrl *owner;
  wxListBox *vehicleList;
  Router *router;

public:
  wxButton *submit;
  wxButton *edit;
  wxButton *delete_;
  wxButton *changePage;
  
  VehicleView(wxWindow *window, Router *router);
  virtual ~VehicleView();

  wxString getMakeValue() const { return make->GetValue(); }
  wxString getModelValue() const { return model->GetValue(); }
  int getYearValue() const { return year->GetValue(); }
  wxString getColorValue() const { return color->GetValue(); }
  wxString getLicensePlateValue() const { return licensePlate->GetValue(); }
  wxString getVinValue() const { return vin->GetValue(); }
  wxString getOwnerValue() const { return owner->GetValue(); }

  void addVehicleToList(const wxString &vehicle);
  void clearForm();
  int getSelectedVehicle() const { return vehicleList->GetSelection(); }
  wxString getSelectedVehicleString() const { return vehicleList->GetString(vehicleList->GetSelection()); }
};

#endif // !VEHICLE_VIEW_HPP
