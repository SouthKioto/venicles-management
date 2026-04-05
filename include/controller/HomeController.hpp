#ifndef HOMECONTROLLER_HPP
#define HOMECONTROLLER_HPP

#include "../include/model/HomeModel.hpp"
#include "../include/view/HomeView.hpp"
#include <wx/event.h>

class Router;

class HomeController {
private:
  HomeView *_view;
  HomeModel *_model;

public:
  Router *router;
  HomeController(HomeView *view, HomeModel *model, Router *router);
  ~HomeController();
  void OnChangePageClicked(wxCommandEvent &event);
};

#endif // !HOMECONTROLLER_HPP
