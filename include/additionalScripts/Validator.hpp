#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include "Logger.hpp"
#include <algorithm>
#include <cctype>
#include <regex>
#include <string>
#include <vector>

class Validator {
private:
  Logger &logger;
  std::vector<std::string> errors;

public:
  Validator(Logger &loggerInstance);

  bool validateEmail(const std::string &email);

  bool validatePassword(const std::string &password);

  bool checkEmpty(const std::string &value);

  std::vector<std::string> getErrors();
};

#endif
