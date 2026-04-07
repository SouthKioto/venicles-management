#include "../../include/database/SQLiteDatabase.hpp"
#include <sqlite3.h>

SQLiteDatabase::SQLiteDatabase(const std::string &filename)
    : db(nullptr), filename(filename) {
  std::string path = db_path + filename;
  int result = sqlite3_open(path.c_str(), &db);

  if (result != SQLITE_OK || db == nullptr) {
    logger.log(LogLevel::Error, "Nie można otworzyć bazy danych SQLite: " + path);
    db = nullptr;
    return;
  }

  if (!createTables()) {
    logger.log(LogLevel::Error, "Nie można utworzyć tabel w bazie danych SQLite");
  }
}

SQLiteDatabase::~SQLiteDatabase() {
  if (db != nullptr) {
    sqlite3_close(db);
    db = nullptr;
  }
}

bool SQLiteDatabase::executeSQL(const std::string &sql) {
  if (db == nullptr) {
    return false;
  }

  char *errorMessage = nullptr;
  int result = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errorMessage);

  if (result != SQLITE_OK) {
    if (errorMessage != nullptr) {
      logger.log(LogLevel::Error, "SQLite error: " + std::string(errorMessage));
      sqlite3_free(errorMessage);
    }
    return false;
  }

  return true;
}

bool SQLiteDatabase::createTables() {
  const std::string usersTable =
      "CREATE TABLE IF NOT EXISTS users ("
      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
      "name TEXT NOT NULL, "
      "surname TEXT NOT NULL, "
      "email TEXT UNIQUE NOT NULL, "
      "password TEXT NOT NULL, "
      "age INTEGER NOT NULL"
      ");";

  const std::string vehiclesTable =
      "CREATE TABLE IF NOT EXISTS vehicles ("
      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
      "make TEXT NOT NULL, "
      "model TEXT NOT NULL, "
      "plate TEXT NOT NULL, "
      "year INTEGER NOT NULL" 
      ");";

  return executeSQL(usersTable) && executeSQL(vehiclesTable);
}

bool SQLiteDatabase::userExists(const std::string &email) {
  if (db == nullptr) {
    return false;
  }

  const std::string sql = "SELECT COUNT(1) FROM users WHERE email = ?;";
  sqlite3_stmt *statement = nullptr;
  int result = sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, nullptr);

  if (result != SQLITE_OK) {
    sqlite3_finalize(statement);
    return false;
  }

  sqlite3_bind_text(statement, 1, email.c_str(), -1, SQLITE_TRANSIENT);

  bool exists = false;
  if (sqlite3_step(statement) == SQLITE_ROW) {
    exists = sqlite3_column_int(statement, 0) > 0;
  }

  sqlite3_finalize(statement);
  return exists;
}

bool SQLiteDatabase::insertUser(const User &user) {
  if (db == nullptr) {
    return false;
  }

  if (userExists(user.getEmail())) {
    logger.log(LogLevel::Warning, "Użytkownik o podanym adresie email już istnieje");
    return false;
  }

  const std::string sql =
      "INSERT INTO users (name, surname, email, password, age) VALUES (?, ?, ?, ?, ?);";
  sqlite3_stmt *statement = nullptr;
  int result = sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, nullptr);

  if (result != SQLITE_OK) {
    sqlite3_finalize(statement);
    return false;
  }

  sqlite3_bind_text(statement, 1, user.getName().c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(statement, 2, user.getSurname().c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(statement, 3, user.getEmail().c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(statement, 4, user.getPassword().c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_int(statement, 5, user.getAge());

  bool success = sqlite3_step(statement) == SQLITE_DONE;
  sqlite3_finalize(statement);

  if (!success) {
    logger.log(LogLevel::Error, "Nie udało się zarejestrować użytkownika w SQLite");
  }

  return success;
}

bool SQLiteDatabase::insertVehicle(const Venicle &vehicle) {
  if (db == nullptr) {
    return false;
  }

  const std::string sql =
      "INSERT INTO vehicles (make, model, plate, year) VALUES (?, ?, ?, ?);";
  sqlite3_stmt *statement = nullptr;
  int result = sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, nullptr);

  if (result != SQLITE_OK) {
    sqlite3_finalize(statement);
    return false;
  }

  sqlite3_bind_text(statement, 1, vehicle.getMake().c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(statement, 2, vehicle.getModel().c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(statement, 3, vehicle.getPlate().c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_int(statement, 4, vehicle.getYear());

  bool success = sqlite3_step(statement) == SQLITE_DONE;
  sqlite3_finalize(statement);

  if (!success) {
    logger.log(LogLevel::Error, "Nie udało się dodać pojazdu do SQLite");
  }

  return success;
}

std::vector<Venicle> SQLiteDatabase::getAllVehicles() {
  std::vector<Venicle> resultList;

  if (db == nullptr) {
    return resultList;
  }

  const std::string sql = "SELECT id, make, model, plate, year FROM vehicles;";
  sqlite3_stmt *statement = nullptr;
  int result = sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, nullptr);

  if (result != SQLITE_OK) {
    sqlite3_finalize(statement);
    return resultList;
  }

  while (sqlite3_step(statement) == SQLITE_ROW) {
    Venicle vehicle;
    vehicle.setId(sqlite3_column_int(statement, 0));
    vehicle.setMake(reinterpret_cast<const char *>(sqlite3_column_text(statement, 1)));
    vehicle.setModel(reinterpret_cast<const char *>(sqlite3_column_text(statement, 2)));
    vehicle.setPlate(reinterpret_cast<const char *>(sqlite3_column_text(statement, 3)));
    vehicle.setYear(sqlite3_column_int(statement, 4));
    resultList.push_back(vehicle);
  }

  sqlite3_finalize(statement);
  return resultList;
}
