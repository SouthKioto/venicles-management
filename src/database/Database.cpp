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

  // INFO: default tables on database init
  tables = {"CREATE TABLE IF NOT EXISTS users("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "name           TEXT    NOT NULL, "
            "surname        TEXT    NOT NULL, "
            "email          TEXT    NOT NULL, "
            "password       TEXT    NOT NULL, "
            "isAdmin        BOOL     NOT NULL);",

            "CREATE TABLE IF NOT EXISTS vehicle("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "brand          TEXT    NOT NULL, "
            "model          TEXT    NOT NULL, "
            "year           TEXT    NOT NULL, "
            "color          TEXT    NOT NULL);",

            "CREATE TABLE IF NOT EXISTS userVehicle("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "idUser         INTEGER    NOT NULL, "
            "idVehicle      INTEGER    NOT NULL, "
            "date           TEXT       NOT NULL);",

            "CREATE TABLE IF NOT EXISTS settings("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "settingName    TEXT       NOT NULL, "
            "value          INTEGER    NOT NULL);"};

  // INFO: default isertions on database init
  insertions = {
      "INSERT OR IGNORE INTO users (name, surname, email, password, isAdmin) "
      "VALUES('admin', 'admin', 'admin@example.com', '123', 1);",

      "INSERT OR IGNORE INTO users (name, surname, email, password, isAdmin) "
      "VALUES('Jan', 'Kowalski', 'JanK@example.com', '321', 0);",

      "INSERT OR IGNORE INTO vehicle (brand, model, year, color) "
      "VALUES('Toyota', 'Yaris', '2006', 'RED');",

      "INSERT OR IGNORE INTO vehicle (brand, model, year, color) "
      "VALUES('BMW', 'x5', '2007', 'WHITE');",

      "INSERT OR IGNORE INTO userVehicle (idUser, idVehicle, date) "
      "VALUES(1, 1, '00-00-0000');",

      //"INSERT INTO settings (settingName, value) ",
      //"VALUES('noweUstawienie', 0);",
  };

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
