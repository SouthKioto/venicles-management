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

  std::string query =
      "INSERT INTO USERS (NAME, SURNAME, EMAIL, ISADMIN) "
      "VALUES('Jan', 'Kowalski', 'jKowalski@example.com', 'false')";

  database->executeQuery(query);

  // INFO: labda
  auto mapToUser = [](sqlite3_stmt *stmt) -> User {
    User user;
    user.setId(sqlite3_column_int(stmt, 0));
    user.setName((const char *)sqlite3_column_text(stmt, 1));
    user.setSurname((const char *)sqlite3_column_text(stmt, 2));
    user.setEmail((const char *)sqlite3_column_text(stmt, 3));
    user.setAdminPermission((bool)sqlite3_column_int(stmt, 4));
    return user;
  };

  std::string sql = "SELECT * FROM USERS";

  std::vector<User> people = database->fetch<User>(sql, mapToUser);

  wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
  sizer->Add(container, 1, wxEXPAND);
  this->SetSizer(sizer);
  this->Layout();

  this->SetSize(800, 600);
  this->Refresh();
}