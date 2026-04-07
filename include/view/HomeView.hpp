#ifndef HOMEVIEW_HPP
#define HOMEVIEW_HPP

#include <wx/wx.h>
#include <vector>
#include "../classes/Venicle.hpp"

class Router;

class HomeView : public wxPanel {
private:
  Router *router;
  wxListBox *vehicleList;

public:
  wxButton *changePage;

  HomeView(wxWindow *window, Router *router);
  virtual ~HomeView();

  void setVehicles(const std::vector<Venicle> &vehicles);
};

#endif // !HOMEVIEW_HPP
