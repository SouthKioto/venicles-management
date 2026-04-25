#ifndef REGISTER_MODEL_HPP
#define REGISTER_MODEL_HPP

#include "../include/additionalScripts/Logger.hpp"
#include "../include/database/Database.hpp"
#include <string>
#include <vector>

class RegisterModel {
private:
  Database *conn;
  Logger *logger;
  std::vector<std::string> errors;

public:
  RegisterModel(Database *conn, Logger *logger);

  bool checkUserExists(const std::string &email);
  bool registerUser(const std::string &name, const std::string &surname,
                    const std::string &email, const std::string &password);

  std::vector<std::string> getErrors();
};

#endif // !REGISTER_MODEL_HPP
