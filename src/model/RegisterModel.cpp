#include "../include/model/RegisterModel.hpp"

RegisterModel::RegisterModel(Database *conn, Logger *logger)
    : conn(conn), logger(logger) {
  errors.clear();
}

std::vector<std::string> RegisterModel::getErrors() {
  std::vector<std::string> tmpErr = this->errors;
  this->errors.clear();
  return tmpErr;
}

bool RegisterModel::checkUserExists(const std::string &email) {
  errors.clear();

  struct Row {
    std::string email;
  };

  auto mapper = [](sqlite3_stmt *stmt) -> Row {
    Row r;
    r.email = (const char *)sqlite3_column_text(stmt, 0);
    return r;
  };

  std::string safeEmail = email;
  // Escape pojedynczych apostrofow (SQLite: '' zamiast ')
  size_t pos = 0;
  while ((pos = safeEmail.find('\'', pos)) != std::string::npos) {
    safeEmail.replace(pos, 1, "''");
    pos += 2;
  }

  std::string sql =
      "SELECT email FROM users WHERE email = '" + safeEmail + "' LIMIT 1;";

  auto rows = this->conn->fetch<Row>(sql, mapper);

  if (!rows.empty()) {
    logger->log(LogLevel::Error, "Uzytkownik z tym emailem juz istnieje");
    errors.push_back("Uzytkownik z tym adresem email juz istnieje");
    return true;
  }
  return false;
}

bool RegisterModel::registerUser(const std::string &name,
                                 const std::string &surname,
                                 const std::string &email,
                                 const std::string &password) {
  errors.clear();

  auto escape = [](const std::string &val) -> std::string {
    std::string out = val;
    size_t pos = 0;
    while ((pos = out.find('\'', pos)) != std::string::npos) {
      out.replace(pos, 1, "''");
      pos += 2;
    }
    return out;
  };

  std::string sql =
      "INSERT INTO users (name, surname, email, password, isAdmin) VALUES('" +
      escape(name) + "', '" + escape(surname) + "', '" + escape(email) +
      "', '" + escape(password) + "', 'false');";

  try {
    this->conn->executeQuery(sql);
    logger->log(LogLevel::Info, "Zarejestrowano uzytkownika: " + email);
    return true;
  } catch (...) {
    logger->log(LogLevel::Critical, "Blad podczas rejestracji uzytkownika");
    errors.push_back("Blad podczas rejestracji. Sprobuj ponownie.");
    return false;
  }
}
