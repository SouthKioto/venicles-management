#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "../additionalScripts/Logger.hpp"
#include "../nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <vector>

class Database {
private:
  std::string filename;
  std::string const db_path = "src/database/";
  Logger logger;

public:
  Database(std::string filename);

  ~Database();

  template <typename T> void writeInto(T &obiekt) {
    nlohmann::json serialize = obiekt;

    std::ofstream file(this->db_path + this->filename);

    if (file.is_open()) {
      file << serialize.dump(4);
      file.close();

      this->logger.log(LogLevel::Info, "Dane dodane do pliku");
    } else {
      this->logger.log(LogLevel::Error, "Blad otwarcia pliku");
    }
  };

  template <typename T> T getFrom(std::string &sciezka) {
    std::ifstream plik(sciezka);

    if (!plik.is_open()) {
      this->logger.log(LogLevel::Error, "Nie można otworzyć pliku " + sciezka);
    }

    nlohmann::json deserialize;
    plik >> deserialize;

    return deserialize.get<T>();
  }

  template <typename T>
  bool update(std::string &sciezka, int id, T &updatedData) {

    std::ifstream plik(sciezka);

    nlohmann::json data;

    if (!plik.is_open()) {
      this->logger.log(LogLevel::Error, "Nie można otworzyć pliku " + sciezka);
      return false;
    }

    try {
      plik >> data;

    } catch (const nlohmann::json::parse_error &e) {
      this->logger.log(LogLevel::Critical,
                       "Blad parsowania JSON: " + std::string(e.what()));
    }

    std::vector<T> parsed_data = data.get<std::vector<T>>();

    bool found = false;

    for (T &item : parsed_data) {
      if (item.id == id) {
        item = updatedData;
        item.id = id;
        found = true;
        break;
      }
    }

    if (!found) {
      this->logger.log(LogLevel::Warning,
                       "Nie znaleziono podanego id: " + std::to_string(id));
      return false;
    }

    std::ofstream plik_wyjs(sciezka);
    if (!plik_wyjs.is_open()) {
      this->logger.log(LogLevel::Error, "Nie można otworzyć pliku " + sciezka);
      return false;
    }

    nlohmann::json updatedJson = parsed_data;

    plik_wyjs << updatedJson.dump(4);

    return true;
  };
};

#endif // !DATABASE_HPP
