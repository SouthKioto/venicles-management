#include "../../include/controller/HomeController.hpp"
#include "../../include/classes/Router.hpp"
#include "../../include/database/SQLiteDatabase.hpp"
#include "../../include/classes/Venicle.hpp"

HomeController::HomeController(HomeView *view, SQLiteDatabase *db, Router *router)
    : _view(view), _db(db), router(router) {

  _view->changePage->Bind(wxEVT_BUTTON, &HomeController::OnChangePageClicked,
                          this);

  std::vector<Venicle> vehicles = _db->getAllVehicles();
  _view->setVehicles(vehicles);
}

void HomeController::OnChangePageClicked(wxCommandEvent &event) {
  this->router->navigate("login");
}
