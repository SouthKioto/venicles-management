#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <regex>
#include "Logger.hpp"

class Validator {
    private:
        Logger& logger;
        std::vector<std::string> errors;

    public:
        Validator(Logger& loggerInstance);

        bool validateEmail(std::string& email);

        bool validatePassword(std::string& password);

        bool checkEmpty (std::string& value);

        std::vector<std::string> getErrors();
};


#endif