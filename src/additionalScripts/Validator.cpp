#include "../../include/additionalScripts/Validator.hpp"

#include <algorithm>
#include <cctype>

Validator::Validator(Logger& loggerInstance) : logger(loggerInstance) {};


bool Validator::validateEmail(std::string& email) {
    // Warunek 1) -> czy mail zawiera znak '@' 
    if (email.find('@') == std::string::npos) {
    errors.push_back("Wrong email address.");
    logger.log(LogLevel::Error, "Failed email validation: " + email);
    return false;
}

logger.log(LogLevel::Info, "Succesfull email validation.");
return true;

}

bool Validator::validatePassword(std::string& password) {
    // Warunek 1) -> Wymagany minimalny rozmiar dla hasła: 13 znaków
    if (password.length() < 13) {
        errors.push_back("Password is too short");
        logger.log(LogLevel::Error, "Password is too short.");
        return false;
    }

    // Warunek 2) -> Hasło musi zawierać przynajmniej jedną cyfrę
    bool flag = false;
    for (int i = 0; i <= password.length() - 1; i++) {
        if (isdigit(password[i])) {
            flag = true;
            break;
        }
    }

    if (!flag) {
        errors.push_back("Password must contain at least one digit.");
        logger.log(LogLevel::Error, "Password must contain at least one digit.");
        return false;
    }

    // Warunek 3) -> Hasło musi zawierać przynajmniej jedną dużą literę
    if (any_of(password.begin(), password.end(), [](unsigned char c) { return isupper(c); }) == false) {
        errors.push_back("Password must contain at least one uppercase letter.");
        logger.log(LogLevel::Error, "Password must contain at least one uppercase letter.");
        return false;
    }
}

bool Validator::checkEmpty(std::string& value) {
    if(value.empty()) {
        errors.push_back("Value can't be empty.");
        logger.log(LogLevel::Error, "Value can't be empty.");
        return true;
    }
    return false;
}

std::vector<std::string> Validator::getErrors() {
    return errors;
};
