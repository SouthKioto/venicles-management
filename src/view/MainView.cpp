#include "../include/view/MainView.hpp"
#include "../include/classes/Router.hpp"
#include "../include/controller/HomeController.hpp"
#include "../include/controller/LoginController.hpp"
#include "../include/controller/RegisterController.hpp"
#include "../include/database/Database.hpp"
#include "../include/model/HomeModel.hpp"
#include "../include/model/LoginModel.hpp"
#include "../include/model/RegisterModel.hpp"
#include "../include/view/HomeView.hpp"
#include "../include/view/LoginView.hpp"
#include "../include/view/RegisterView.hpp"

MainView::MainView(Logger *logger, Database *database)
    : wxFrame(NULL, wxID_ANY, "Venicle Management App") {

  this->database = database;
  this->logger = logger;

  this->SetSize(800, 600);
  wxPanel *container = new wxPanel(this);

  router = new Router(container, logger);

  // modele
  LoginModel *loginModel = new LoginModel(database, logger);
  HomeModel *homeModel = new HomeModel();
  RegisterModel *registerModel = new RegisterModel();

  // widoki
  LoginView *loginView = new LoginView(container, router);
  HomeView *homeView = new HomeView(container, router);
  RegisterView *registerView = new RegisterView(container, router);

  // kotrolery
  new LoginController(loginModel, loginView, router);
  new HomeController(homeView, homeModel, router);
  new RegisterController(registerModel, registerView, router);

  homeView->Hide();
  registerView->Hide();

  router->add("login", loginView);
  router->add("home", homeView);
  router->add("register", registerView);

  router->navigate("login");

  wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
  sizer->Add(container, 1, wxEXPAND);

  this->SetSizer(sizer);
  this->Layout();
  this->Refresh();

  router->navigate("login");
}
