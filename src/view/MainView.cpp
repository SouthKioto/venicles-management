#include "../../include/view/MainView.hpp"
#include "../../include/classes/Router.hpp"
#include "../../include/controller/HomeController.hpp"
#include "../../include/controller/LoginController.hpp"
#include "../../include/model/RegistrationModel.hpp"
#include "../../include/view/HomeView.hpp"
#include "../../include/view/LoginView.hpp"
#include "../../include/database/SQLiteDatabase.hpp"

MainView::MainView() : wxFrame(NULL, wxID_ANY, "Venicle Management App") {
  wxPanel *container = new wxPanel(this);

  router = new Router(container);

  SQLiteDatabase *database = new SQLiteDatabase("app.db");

  // modele
  RegistrationModel *registrationModel = new RegistrationModel(database);

  // widoki
  LoginView *loginView = new LoginView(container, router);
  HomeView *homeView = new HomeView(container, router);

  // kontrole
  new LoginController(registrationModel, loginView, router);
  new HomeController(homeView, database, router);

  homeView->Hide();

  router->add("login", loginView);
  router->add("home", homeView);

  wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
  sizer->Add(container, 1, wxEXPAND);
  this->SetSizer(sizer);

  router->navigate("login");
}
