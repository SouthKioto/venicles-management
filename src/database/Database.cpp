#include "../include/database/Database.hpp"
#include "../include/additionalScripts/Logger.hpp"

Database::Database(Logger *logger) : logger(logger) {};

Database::~Database() {};

void Database::initDatabase() {
  const char *nazwaDB = "database.db";
  char *messageError;
  bool success = true;

  std::vector<std::string> tables;
  std::vector<std::string> insertions;
  std::vector<std::string> errors;

  tables = {"CREATE TABLE IF NOT EXISTS PERSON("
            "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
            "NAME           TEXT    NOT NULL, "
            "SURNAME        TEXT    NOT NULL, "
            "EMAIL          TEXT    NOT NULL, "
            "AGE            INT     NOT NULL);",

            "CREATE TABLE IF NOT EXISTS VEHICLE("
            "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
            "BRAND          TEXT    NOT NULL, "
            "MODEL          TEXT    NOT NULL, "
            "YEAR           TEXT    NOT NULL, "
            "COLOR          TEXT    NOT NULL);"};

  insertions = {"INSERT INTO PERSON (NAME, SURNAME, EMAIL, AGE) "
                "VALUES('admin', 'admin', 'admin@example.com', 21)",

                "INSERT INTO VEHICLE (BRAND, MODEL, YEAR, COLOR)"
                "VALUES('Toyota', 'Yaris', '2005', 'Red')",

                "INSERT INTO VEHICLES (BRAND, MODEL, YEAR, COLOR)"
                "VALUES('Toyota', 'Yaris', '2005', 'Red')",

                "INSERT INTO VEHICLES (BRAND, MODEL, YEAR, COLOR)"
                "VALUES('Toyota', 'Yaris', '2005', 'Red')"};

  if (sqlite3_open(nazwaDB, &db) != SQLITE_OK) {
    logger->log(LogLevel::Critical, sqlite3_errmsg(db));
    return;
  }

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
    // TODO: przerobić na globalną tablice w klasie
    // do logowania kazdego bledu (INSERT, UPDATE, DELETE)
    std::string messageErrors = "Baza nie utworzona. Bledy:\n";
    int i = 1;
    for (const std::string &error : errors) {
      messageErrors += std::to_string(i) + ". " + error + "\n";
      i++;
    }

    logger->log(LogLevel::Critical, messageErrors);
  } else {
    logger->log(LogLevel::Info,
                "Baza danych utworzona pod nazwa: " + (std::string)nazwaDB);
  }

  sqlite3_close(db);
}
