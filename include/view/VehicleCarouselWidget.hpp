#ifndef VEHICLECAROUSELWIDGET_HPP
#define VEHICLECAROUSELWIDGET_HPP

#include "../include/model/VehicleSummary.hpp"
#include <vector>
#include <wx/wx.h>

// Enkapsuluje lewy panel (slider aut) i prawy panel (podsumowanie rezerwacji).
class VehicleCarouselWidget : public wxPanel {
public:
  VehicleCarouselWidget(wxWindow *parent,
                        const std::vector<VehicleSummary> &vehicles);
};

#endif // !VEHICLECAROUSELWIDGET_HPP
