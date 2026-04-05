#include "../include/controller/HomeController.hpp"
#include "../include/classes/Router.hpp"

HomeController::HomeController(HomeView *view, HomeModel *model, Router *router)
    : _view(view), _model(model), router(router) {

  _view->changePage->Bind(wxEVT_BUTTON, &HomeController::OnChangePageClicked,
                          this);
}

void HomeController::OnChangePageClicked(wxCommandEvent &event) {
  this->router->navigate("login");
}
