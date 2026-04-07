#include "../include/database/Database.hpp"
#include "../include/additionalScripts/Logger.hpp"

Logger log;

Database::Database() {};

Database::~Database() {};

void Database::createDatabase() {
  char *nazwaDB = "database.db";
  error = sqlite3_open(nazwaDB, &db);
  if (error) {
    log.log(LogLevel::Critical, "Nie udało sie uworzyc bazy danych: " +
                                    (std::string)sqlite3_errmsg(db));
  } else {
    log.log(LogLevel::Info,
            "Baza danych utworzona pod nazwa: " + (std::string)nazwaDB);
  }
  sqlite3_close(db);
}
