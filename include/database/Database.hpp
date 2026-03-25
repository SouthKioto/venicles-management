#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "../additionalScripts/Logger.hpp"
#include "../nlohmann/json.hpp"
#include <fstream>
#include <iostream>

class Database {
private:
  std::string filename;
  std::string db_path = "src/database/";

public:
  Database(std::string filename);

  ~Database();

  template <typename T> void writeInto(T &obiekt) {
    Logger logger;
    nlohmann::json serialize = obiekt;

    std::ofstream file(this->db_path + this->filename);

    if (file.is_open()) {
      // setw(4);

      file << serialize.dump(4);
      file.close();

      logger.log(LogLevel::Info, "Dane dodane do pliku");
    } else {
      logger.log(LogLevel::Error, "Blad otwarcia pliku");
    }
  };
};

#endif // !DATABASE_HPP
