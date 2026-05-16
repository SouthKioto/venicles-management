#include "../include/view/MainView.hpp"
#include "../include/additionalScripts/Validator.hpp"
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

#include <memory>

MainView::MainView(Logger *logger, Database *database)
    : wxFrame(NULL, wxID_ANY, "Venicle Management App") {
  this->database = database;
  this->logger = logger;

  SetClientSize(wxSize(600, 400));

  validator = std::make_unique<Validator>(*logger);

  wxPanel *container = new wxPanel(this);
  router = std::make_unique<Router>(container, logger);

  LoginModel *loginModel = new LoginModel(database, logger);
  RegisterModel *registerModel = new RegisterModel(database, logger);
  HomeModel *homeModel = new HomeModel(database, logger);

  LoginView *loginView = new LoginView(container, router);
  HomeView *homeView = new HomeView(container, router, database, logger);
  RegisterView *registerView = new RegisterView(container, router);

  loginController = std::make_unique<LoginController>(
      loginModel.get(), loginView, router.get(), this->database, this->logger,
      validator.get());

  homeController =
      std::make_unique<HomeController>(homeView, homeModel.get(), router.get());

  registerController = std::make_unique<RegisterController>(
      registerModel.get(), registerView, router.get(), this->logger,
      validator.get());

  router->add("login", loginView);
  router->add("home", homeView);
  router->add("register", registerView);

  homeView->Hide();
  registerView->Hide();

  wxBoxSizer *containerSizer = new wxBoxSizer(wxVERTICAL);

  containerSizer->Add(loginView, 1, wxEXPAND);
  containerSizer->Add(registerView, 1, wxEXPAND);
  containerSizer->Add(homeView, 1, wxEXPAND);

  container->SetSizer(containerSizer);

  wxBoxSizer *frameSizer = new wxBoxSizer(wxVERTICAL);
  frameSizer->Add(container, 1, wxEXPAND);
  this->SetSizer(frameSizer);

  router->navigate("login");
  container->Layout();
  this->Layout();
  this->Centre(wxBOTH);
  this->Raise();
  this->Update();
}

MainView::~MainView() = default;
