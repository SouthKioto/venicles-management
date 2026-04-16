#include "../include/model/LoginModel.hpp"
#include "../include/classes/User.hpp"
#include <vector>

LoginModel::LoginModel(Database *conn, Logger *logger)
    : conn(conn), logger(logger) {
  errors.clear();
}

std::vector<std::string> LoginModel::getErrors() { return this->errors; }
bool LoginModel::getLoginFlag() { return this->canLogIn; }

LoginModel &LoginModel::setUserData(User *user) {
  if (!user) {
    logger->log(LogLevel::Critical, "User are null");
    this->canLogIn = false;
  }
  this->user = user;

  return *this;
}

LoginModel &LoginModel::checkUserExist() {
  std::vector<User> users;
  errors.clear();

  std::cout << user->getEmail() << std::endl;

  auto mapToUser = [](sqlite3_stmt *stmt) -> User {
    User user;
    user.setEmail((const char *)sqlite3_column_text(stmt, 0));

    return user;
  };

  std::string sql =
      "SELECT email FROM users WHERE email = '" + user->getEmail() + "';";

  users = this->conn->fetch<User>(sql, mapToUser);

  for (User userdata : users) {
    std::cout << userdata.getEmail() << std::endl;
  }

  if (users.empty()) {
    logger->log(LogLevel::Error, "User doesnt exist");
    errors.push_back("User doesnt exist. Please register");

    this->canLogIn = false;
  }
  return *this;
}

LoginModel &LoginModel::checkPassword() {
  std::vector<User> users;
  errors.clear();
  std::string passFromForm = user->getPassword();

  auto mapToUser = [](sqlite3_stmt *stmt) -> User {
    User user;
    user.setPassword((const char *)sqlite3_column_text(stmt, 0));
    return user;
  };

  std::string sql =
      "SELECT password FROM users WHERE email = '" + user->getEmail() + "';";

  users = this->conn->fetch<User>(sql, mapToUser);

  if (users.empty()) {
    logger->log(LogLevel::Error, "User doesnt exist");
    errors.push_back("User doesnt exist");

    this->canLogIn = false;
    return *this;
  }

  if (passFromForm != users[0].getPassword()) {
    logger->log(LogLevel::Error, "Passwords are not same");

    errors.push_back("Passwords are not same");

    this->canLogIn = false;

    return *this;
  }

  logger->log(LogLevel::Error, "Password are correct");

  return *this;
};
