#ifndef LOGIN_MODEL_HPP
#define LOGIN_MODEL_HPP

#include "../include/additionalScripts/Logger.hpp"
#include "../include/database/Database.hpp"
#include "./classes/User.hpp"
#include <string>

/**
 * @class LoginModel
 * @brief Odpowiada za logowanie uzytkownika
 */
class LoginModel {

private:
  User *user;
  Database *conn;
  Logger *logger;

  std::vector<std::string> errors;
  bool canLogIn = true;

public:
  LoginModel(Database *conn, Logger *logger);

  bool getLoginFlag();

  LoginModel &setUserData(User *user);
  LoginModel &checkUserExist();
  LoginModel &checkPassword();

  std::vector<std::string> getErrors();
};

#endif // !LOGIN_MODEL_HPP
