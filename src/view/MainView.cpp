#include "../include/view/MainView.hpp"
#include "../include/additionalScripts/Validator.hpp"
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

  Validator *validator = new Validator(*logger);

  SetClientSize(wxSize(600, 400));

  wxPanel *container = new wxPanel(this);
  router = new Router(container, logger);

  LoginModel *loginModel = new LoginModel(database, logger);
  HomeModel *homeModel = new HomeModel();

  LoginView *loginView = new LoginView(container, router);
  HomeView *homeView = new HomeView(container, router);

  new LoginController(loginModel, loginView, router, this->database,
                      this->logger, validator);
  new HomeController(homeView, homeModel, router);

  homeView->Hide();
  router->add("login", loginView);
  router->add("home", homeView);

  wxBoxSizer *containerSizer = new wxBoxSizer(wxVERTICAL);
  containerSizer->Add(loginView, 1, wxEXPAND);
  containerSizer->Add(homeView, 1, wxEXPAND);
  container->SetSizer(containerSizer);

  wxBoxSizer *frameSizer = new wxBoxSizer(wxVERTICAL);
  frameSizer->Add(container, 1, wxEXPAND);
  this->SetSizer(frameSizer);

  router->navigate("login");
}
