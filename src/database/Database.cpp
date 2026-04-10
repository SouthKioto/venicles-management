#include "../include/database/Database.hpp"
#include "../include/additionalScripts/Logger.hpp"

Database::Database(Logger *logger) : logger(logger) {};

Database::~Database() {
  if (db) {
    sqlite3_close(db);
    db = nullptr;
  }
};

void Database::checkConnection() {
  if (db != nullptr) {
    return;
  }

  if (sqlite3_open(nazwaDB, &db) != SQLITE_OK) {
    logger->log(LogLevel::Critical, "Nie udalo sie otworzyc bazy: " +
                                        std::string(sqlite3_errmsg(db)));
    sqlite3_close(db);
    db = nullptr;
  }
}

std::string Database::errorLog(std::string &message,
                               std::vector<std::string> &errors) {

  int i = 1;
  for (const std::string &error : errors) {
    message += std::to_string(i) + ". " + error + "\n";
    i++;
  }

  return message;
}

void Database::initDatabase() {
  char *messageError;
  bool success = true;

  this->checkConnection();

  tables = {"CREATE TABLE IF NOT EXISTS USERS("
            "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
            "NAME           TEXT    NOT NULL, "
            "SURNAME        TEXT    NOT NULL, "
            "EMAIL          TEXT    NOT NULL, "
            "ISADMIN        BOOL     NOT NULL);",

            "CREATE TABLE IF NOT EXISTS VEHICLE("
            "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
            "BRAND          TEXT    NOT NULL, "
            "MODEL          TEXT    NOT NULL, "
            "YEAR           TEXT    NOT NULL, "
            "COLOR          TEXT    NOT NULL);"};

  insertions = {"INSERT INTO USERS (NAME, SURNAME, EMAIL, ISADMIN) "
                "VALUES('admin', 'admin', 'admin@example.com', 'true')"};

  for (const std::string &sql : tables) {
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &messageError) !=
        SQLITE_OK) {
      success = false;
      errors.push_back(std::string(messageError));
      sqlite3_free(messageError);
    }
  }

  for (const std::string &sql : insertions) {
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &messageError) !=
        SQLITE_OK) {
      success = false;
      errors.push_back(std::string(messageError));
      sqlite3_free(messageError);
    }
  }

  if (!success) {
    std::string mess = "Blad tworzenia bazy danych: ";

    std::string messageErrors = Database::errorLog(mess, errors);

    logger->log(LogLevel::Critical, messageErrors);
  } else {
    logger->log(LogLevel::Info,
                "Baza danych utworzona pod nazwa: " + (std::string)nazwaDB);
  }
}

void Database::executeQuery(const std::string &query) {
  this->checkConnection();
  if (!db) {
    return;
  }

  char *messageError = nullptr;
  if (sqlite3_exec(db, query.c_str(), nullptr, nullptr, &messageError) !=
      SQLITE_OK) {
    errors.push_back(std::string(messageError));
    sqlite3_free(messageError);
  } else {
    logger->log(LogLevel::Info, "Wykonano: " + query.substr(0, 6));
  }
}
