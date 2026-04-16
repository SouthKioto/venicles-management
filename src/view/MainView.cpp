#include "../include/view/MainView.hpp"
#include "../include/classes/Router.hpp"
#include "../include/controller/HomeController.hpp"
#include "../include/controller/LoginController.hpp"
#include "../include/database/Database.hpp"
#include "../include/model/HomeModel.hpp"
#include "../include/model/LoginModel.hpp"
#include "../include/view/HomeView.hpp"
#include "../include/view/LoginView.hpp"

MainView::MainView(Logger *logger, Database *database)
    : wxFrame(NULL, wxID_ANY, "Venicle Management App") {

  this->database = database;
  this->logger = logger;

  SetClientSize(wxSize(600, 400));
  wxPanel *container = new wxPanel(this);

  router = new Router(container, logger);

  // modele
  LoginModel loginModel(database, logger);
  HomeModel homeModel;

  // widoki
  LoginView loginView(container, router);
  HomeView homeView(container, router);

  // kotrolery
  new LoginController(&loginModel, &loginView, router);
  new HomeController(&homeView, &homeModel, router);

  homeView.Hide();

  router->add("login", &loginView);
  router->add("home", &homeView);

  router->navigate("login");

  wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
  sizer->Add(container, 1, wxEXPAND);
  this->SetSizer(sizer);

  router->navigate("login");
}
