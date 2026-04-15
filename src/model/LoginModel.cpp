#include "../include/model/LoginModel.hpp"
#include "../include/classes/User.hpp"
#include <vector>

/*
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
*/

void LoginModel::setUserData(User *user) { this->user = user; }

bool LoginModel::checkUserExist() {
  std::vector<User> users;

  auto mapToUser = [](sqlite3_stmt *stmt) -> User {
    User user;
    user.setId(sqlite3_column_int(stmt, 0));
    user.setName((const char *)sqlite3_column_text(stmt, 1));
    user.setSurname((const char *)sqlite3_column_text(stmt, 2));
    user.setEmail((const char *)sqlite3_column_text(stmt, 3));
    user.setAdminPermission((bool)sqlite3_column_int(stmt, 4));
    return user;
  };

  std::string sql =
      "SELECT * FROM PERSON WHERE EMAIL = '" + user->getEmail() + ';';

  users = this->conn->fetch<User>(sql, mapToUser);

  if (!users.empty()) {
    logger->log(LogLevel::Error, "Uzytkownik o takim mailu juz istnieje");

    return false;
  }

  logger->log(LogLevel::Info, "Zalogowano");
  return true;
}

bool LoginModel::checkPassword() {}
