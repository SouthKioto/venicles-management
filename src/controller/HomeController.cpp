#include "../include/controller/HomeController.hpp"
#include "../include/classes/Router.hpp"
#include "../include/classes/Session.hpp"

HomeController::HomeController(HomeView *view, HomeModel *model, Router *router)
    : _view(view), _model(model), router(router) {

  _view->logoutBtn->Bind(wxEVT_BUTTON, &HomeController::OnLogoutClicked, this);
}

void HomeController::OnLogoutClicked(wxCommandEvent &event) {
  Session::getInstance().logout();
  this->router->navigate("login");
}
