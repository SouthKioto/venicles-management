#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "../include/additionalScripts/Logger.hpp"
#include <iostream>
#include <sqlite3.h>

class Database {
private:
  std::string const path = "src/database";
  sqlite3 *db;
  int createDBError = 0;
  int createTablesError = 0;
  int insertError = 0;
  int updateError = 0;
  int deleteError = 0;

public:
  Logger *logger;
  Database(Logger *logger);
  ~Database();

  void initDatabase();
};

#endif // !DATABASE_HPP
