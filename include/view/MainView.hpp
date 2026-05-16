#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include "../include/additionalScripts/Logger.hpp"
#include "../include/database/Database.hpp"
#include <memory>
#include <wx/wx.h>

class Router;
class Validator;

class LoginView;
class LoginModel;
class LoginController;

class RegisterView;
class RegisterModel;
class RegisterController;

class HomeModel;
class HomeView;
class HomeController;

class MainView : public wxFrame {
private:
  std::unique_ptr<Router> router;

  std::unique_ptr<Validator> validator;

  LoginView *loginView;
  std::unique_ptr<LoginModel> loginModel;
  std::unique_ptr<LoginController> loginController;

  RegisterView *registerView;
  std::unique_ptr<RegisterModel> registerModel;
  std::unique_ptr<RegisterController> registerController;

  HomeView *homeView;
  std::unique_ptr<HomeModel> homeModel;
  std::unique_ptr<HomeController> homeController;

public:
  Logger *logger;
  Database *database;
  MainView(Logger *logger, Database *database);
  ~MainView();
};

#endif // !MAINVIEW_HPP
