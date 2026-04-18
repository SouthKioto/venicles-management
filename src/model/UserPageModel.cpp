#include "../include/model/UserPageModel.hpp"

UserPageModel::UserPageModel(User *user, Router *router, Database *database,
                             Logger *logger)
    : user(user), router(router), database(database), logger(logger) {}

void UserPageModel::checkAdmin() {

  // INFO: inaczej sprawdzac isAdmin u usera

  this->isAdmin = false;

  auto mapToUser = [](sqlite3_stmt *stmt) -> User {
    User user;
    user.setAdminPermission((bool)sqlite3_column_text(stmt, 0));

    return user;
  };

  std::string sql =
      "SELECT isAdmin FROM users WHERE email=" + this->user->getEmail() + ";";

  this->database->fetch<User>(sql, mapToUser);
}

void UserPageModel::showAdminSettings() {
  if (this->isAdmin) {
    std::cout << "Ustawienia administratorskie wlaczone flaga" << std::endl;
  } else {
    this->logger->log(LogLevel::Info, "No access");
  }
}

void UserPageModel::getUserData() {}

void UserPageModel::getUserVehicles() {}
