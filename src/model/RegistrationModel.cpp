#include "../include/model/RegistrationModel.hpp"
#include "../include/database/Database.hpp"
#include "../include/additionalScripts/Logger.hpp"
#include <regex>

RegistrationModel::RegistrationModel() : user(nullptr) {}

RegistrationModel::~RegistrationModel() { delete user; }

bool RegistrationModel::registerUser(std::string name, std::string surname,
                                     std::string email, std::string password) {
  if (!validateRegistrationData(name, surname, email, password)) {
    return false;
  }

  if (emailExists(email)) {
    return false;
  }

  Logger *logger = new Logger();
  Database db(logger);
  db.initDatabase();

  std::string query =
      "INSERT INTO USERS (NAME, SURNAME, EMAIL, PASSWORD, ISADMIN) VALUES('" +
      name + "', '" + surname + "', '" + email + "', '" + password + "', 0)";

  db.executeQuery(query);
  delete logger;
  return true;
}

bool RegistrationModel::emailExists(std::string email) {
  Logger *logger = new Logger();
  Database db(logger);
  db.initDatabase();

  std::string query = "SELECT * FROM USERS WHERE EMAIL='" + email + "'";
  auto results = db.fetch<User>(query, [](sqlite3_stmt *stmt) {
    User u;
    u.setId(sqlite3_column_int(stmt, 0));
    u.setName((char *)sqlite3_column_text(stmt, 1));
    u.setSurname((char *)sqlite3_column_text(stmt, 2));
    u.setEmail((char *)sqlite3_column_text(stmt, 3));
    u.setPassword((char *)sqlite3_column_text(stmt, 4));
    u.setAdminPermission(sqlite3_column_int(stmt, 5));
    return u;
  });

  delete logger;
  return !results.empty();
}

bool RegistrationModel::validateRegistrationData(std::string name,
                                                 std::string surname,
                                                 std::string email,
                                                 std::string password) {
  if (name.empty() || surname.empty() || email.empty() || password.empty()) {
    return false;
  }

  std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
  if (!std::regex_match(email, emailRegex)) {
    return false;
  }

  if (password.length() < 6) {
    return false;
  }

  return true;
}
