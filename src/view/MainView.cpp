#include "../include/view/MainView.hpp"
#include "../include/classes/Router.hpp"
#include "../include/controller/HomeController.hpp"
#include "../include/controller/LoginController.hpp"
#include "../include/model/HomeModel.hpp"
#include "../include/model/LoginModel.hpp"
#include "../include/view/HomeView.hpp"
#include "../include/view/LoginView.hpp"

MainView::MainView() : wxFrame(NULL, wxID_ANY, "Venicle Management App") {
  wxPanel *container = new wxPanel(this);

  router = new Router(container);

  // modele
  LoginModel *loginModel = new LoginModel();
  HomeModel *homeModel = new HomeModel();

  // widoki
  LoginView *loginView = new LoginView(container, router);
  HomeView *homeView = new HomeView(container, router);

  // kotrolery
  new LoginController(loginModel, loginView, router);
  new HomeController(homeView, homeModel, router);

  homeView->SetSize(1920, 1000);
  homeView->SetMinSize(wxSize(1920, 1000));
  homeView->Hide();

  router->add("login", loginView);
  router->add("home", homeView);

  router->navigate("login");

  wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
  sizer->Add(container, 1, wxEXPAND);
  this->SetSizer(sizer);
  this->Layout();

  this->SetSize(800, 600);
  this->Refresh();
}