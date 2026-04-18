#ifndef USER_PAGE_MODEL_HPP
#define USER_PAGE_MODEL_HPP

#include "../include/classes/Router.hpp"
#include "../include/classes/User.hpp"
#include "../include/classes/Vehicle.hpp"
#include "../include/database/Database.hpp"

class UserPageModel {
private:
  User *user;
  Router *router;
  Database *database;

  bool isAdmin = false;
  std::vector<Vehicle *> userVehicles;

public:
  UserPageModel(User *user, Router *router, Database *database);
  ~UserPageModel();

  void showUserData();
  void checkAdmin(User *user);
  void showAdminSettings(User *user);
  void getMyVehicles();
};

#endif // !USER_PAGE_MODEL_HPP
