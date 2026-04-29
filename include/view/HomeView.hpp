#ifndef HOMEVIEW_HPP
#define HOMEVIEW_HPP

#include "../include/model/HomeModel.hpp"
#include <vector>
#include <wx/wx.h>

class Router;

class HomeView : public wxPanel {
private:
  Router *router;

public:
  wxButton *logoutBtn;

  HomeView(wxWindow *window, Router *router,
           const std::vector<VehicleSummary> &vehicles);

  void change();
};

#endif // !HOMEVIEW_HPP
