#ifndef SQLITE_DATABASE_HPP
#define SQLITE_DATABASE_HPP

#include "../additionalScripts/Logger.hpp"
#include "../classes/User.hpp"
#include "../classes/Venicle.hpp"
#include <sqlite3.h>
#include <string>
#include <vector>

class SQLiteDatabase {
private:
  sqlite3 *db;
  std::string filename;
  std::string const db_path = "src/database/";
  Logger logger;

  bool executeSQL(const std::string &sql);
  bool createTables();

public:
  SQLiteDatabase(const std::string &filename);
  ~SQLiteDatabase();

  bool insertUser(const User &user);
  bool userExists(const std::string &email);
  bool insertVehicle(const Venicle &vehicle);
  std::vector<Venicle> getAllVehicles();
};

#endif // SQLITE_DATABASE_HPP
