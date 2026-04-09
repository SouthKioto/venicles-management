#ifndef DATABASE_SQLITE_HPP
#define DATABASE_SQLITE_HPP

#include <iostream>
#include <sqlite3.h>

class DatabaseSqlite {
private:
  std::string const path = "src/database";
  sqlite3 *db;
  int error = 0;

public:
  DatabaseSqlite();
  ~DatabaseSqlite();

  void createDatabase();
};

#endif // !DATABASE_SQLITE_HPP
