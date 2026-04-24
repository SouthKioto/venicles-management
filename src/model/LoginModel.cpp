#include "../include/model/LoginModel.hpp"
#include "../include/classes/User.hpp"
#include <vector>

LoginModel::LoginModel(Database *conn, Logger *logger)
    : conn(conn), logger(logger) {
  errors.clear();
}

std::vector<std::string> LoginModel::getErrors() { return this->errors; }

std::vector<User> LoginModel::returnUserData(const std::string &email) {
  std::vector<User> user;

  auto mapToUser = [](sqlite3_stmt *stmt) -> User {
    User user;
    user.setEmail((const char *)sqlite3_column_text(stmt, 0));

    return user;
  };

  std::string sql =
      "SELECT email FROM users WHERE email = '" + email + "'LIMIT 1;";

  user = this->conn->fetch<User>(sql, mapToUser);

  if (user.empty()) {
    logger->log(LogLevel::Critical, "User are empty");
    return {};
  }

  return user;
}

bool LoginModel::checkUserExist(const std::string &email) {
  std::vector<User> user;
  errors.clear();

  if (email.empty()) {
    errors.push_back("Empty email");
    return false;
  }

  auto mapToUser = [](sqlite3_stmt *stmt) -> User {
    User user;
    user.setEmail((const char *)sqlite3_column_text(stmt, 0));

    return user;
  };

  std::string sql = "SELECT email FROM users WHERE email = '" + email + "';";

  user = this->conn->fetch<User>(sql, mapToUser);

  if (user.empty()) {
    logger->log(LogLevel::Error, "User doesnt exist");
    errors.push_back("User doesnt exist. Please register");

    return false;
  }
  return true;
}

bool LoginModel::checkPassword(const std::string &password,
                               const std::string &email) {
  std::vector<User> user;
  errors.clear();

  auto mapToUser = [](sqlite3_stmt *stmt) -> User {
    User user;
    user.setPassword((const char *)sqlite3_column_text(stmt, 0));
    return user;
  };

  std::string sql = "SELECT password FROM users WHERE email = '" + email + "';";

  user = this->conn->fetch<User>(sql, mapToUser);

  if (user.empty()) {
    logger->log(LogLevel::Error, "User doesnt exist");
    errors.push_back("User doesnt exist");

    return false;
  }

  if (password != user[0].getPassword()) {

    // TODO: odszyfrowanie hasla
    logger->log(LogLevel::Error, "Passwords are not same");

    errors.push_back("Passwords are not same");

    return false;
  }

  logger->log(LogLevel::Error, "Password are correct");

  return true;
};
