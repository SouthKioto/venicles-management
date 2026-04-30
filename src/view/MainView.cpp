#include "../include/view/MainView.hpp"
#include "../include/additionalScripts/Validator.hpp"
#include "../include/classes/Router.hpp"
#include "../include/controller/HomeController.hpp"
#include "../include/controller/LoginController.hpp"
#include "../include/controller/RegisterController.hpp"
#include "../include/controller/UserPageController.hpp"
#include "../include/database/Database.hpp"
#include "../include/model/HomeModel.hpp"
#include "../include/model/LoginModel.hpp"
#include "../include/model/RegisterModel.hpp"
#include "../include/model/UserPageModel.hpp"
#include "../include/view/HomeView.hpp"
#include "../include/view/LoginView.hpp"
#include "../include/view/RegisterView.hpp"
#include "../include/view/UserPageView.hpp"

MainView::MainView(Logger *logger, Database *database)
    : wxFrame(NULL, wxID_ANY, "Venicle Management App") {
  this->database = database;
  this->logger = logger;

  SetClientSize(wxSize(600, 400));
  container = new wxPanel(this);
  router = new Router(container, logger);
  containerSizer = new wxBoxSizer(wxVERTICAL);

  Validator *validator = new Validator(*logger);

  LoginModel *loginModel = new LoginModel(database, logger);
  RegisterModel *registerModel = new RegisterModel(database, logger);

  LoginView *loginView = new LoginView(container, router);
  RegisterView *registerView = new RegisterView(container, router);

  new LoginController(loginModel, loginView, router, database, logger,
                      validator, this);
  new RegisterController(registerModel, registerView, router, logger,
                         validator);

  registerView->Hide();

  router->add("login", loginView);
  router->add("register", registerView);

  containerSizer->Add(loginView, 1, wxEXPAND);
  containerSizer->Add(registerView, 1, wxEXPAND);

  container->SetSizer(containerSizer);

  wxBoxSizer *frameSizer = new wxBoxSizer(wxVERTICAL);
  frameSizer->Add(container, 1, wxEXPAND);
  this->SetSizer(frameSizer);

  router->navigate("login");
}

void MainView::initViews() {
  HomeModel *homeModel = new HomeModel();
  UserPageModel *userModel = new UserPageModel(database, logger);

  HomeView *homeView = new HomeView(container, router);
  UserPageView *userPageView = new UserPageView(container);

  new HomeController(homeView, homeModel, router);
  new UserPageController(userPageView, userModel, router);

  homeView->Hide();
  userPageView->Hide();

  router->add("home", homeView);
  router->add("userPage", userPageView);

  containerSizer->Add(homeView, 1, wxEXPAND);
  containerSizer->Add(userPageView, 1, wxEXPAND);

  container->Layout();

  router->navigate("home");
}
