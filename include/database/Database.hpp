#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <sqlite3.h>

class Database {
private:
  std::string const path = "src/database";
  sqlite3 *db;
  int error = 0;

public:
  Database();
  ~Database();

  void createDatabase();
};

#endif // !DATABASE_HPP
