#include "../include/model/RegisterModel.hpp"
#include "../include/classes/User.hpp"

RegisterModel::RegisterModel(Database* conn, Logger* logger) 
    : conn(conn), logger(logger) {
    errors.clear();
}

RegisterModel::~RegisterModel() {}

bool RegisterModel::checkUserExists(const std::string& email) {
    errors.clear();
    if (conn->userExists(email)) {
        errors.push_back("Użytkownik o podanym adresie email już istnieje.");
        logger->log(LogLevel::Warning, "Próba rejestracji na istniejący email: " + email);
        return true;
    }
    return false;
}

bool RegisterModel::registerUser(const std::string& name, const std::string& surname, const std::string& email, const std::string& password) {
    errors.clear();
    conn->addUser(name, surname, email, password);
    logger->log(LogLevel::Info, "Zarejestrowano nowego użytkownika: " + email);
    return true;
}

std::vector<std::string> RegisterModel::getErrors() {
    std::vector<std::string> tmp = errors;
    errors.clear();
    return tmp;
}
