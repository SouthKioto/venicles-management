#ifndef USER_PAGE_MODEL_HPP
#define USER_PAGE_MODEL_HPP

#include "../include/additionalScripts/Logger.hpp"
#include "../include/classes/Router.hpp"
#include "../include/classes/User.hpp"
#include "../include/classes/Vehicle.hpp"
#include "../include/database/Database.hpp"

class UserPageModel {
private:
  User *user;
  Router *router;
  Database *database;
  Logger *logger;

  bool isAdmin = false;
  std::vector<Vehicle *> userVehicles;

public:
  UserPageModel(User *user, Router *router, Database *database, Logger *logger);
  ~UserPageModel();

  void getUserData();
  void checkAdmin();
  void showAdminSettings();
  void getUserVehicles();
};

#endif // !USER_PAGE_MODEL_HPP
