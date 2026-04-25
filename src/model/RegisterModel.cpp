#include "../include/model/RegisterModel.hpp"
#include "../include/classes/User.hpp"

RegisterModel::RegisterModel(Database* conn, Logger* logger) 
    : conn(conn), logger(logger) {
    errors.clear();
}

RegisterModel::~RegisterModel() {}

bool RegisterModel::checkUserExists(const std::string& email) {
    errors.clear();
    
    auto mapToUser = [](sqlite3_stmt* stmt) -> User {
        User user;
        user.setEmail((const char*)sqlite3_column_text(stmt, 0));
        return user;
    };

    // INFO: Sprawdzamy czy email już istnieje w bazie
    std::string sql = "SELECT email FROM users WHERE email = '" + email + "' LIMIT 1;";
    std::vector<User> users = conn->fetch<User>(sql, mapToUser);

    if (!users.empty()) {
        errors.push_back("Użytkownik o podanym adresie email już istnieje.");
        logger->log(LogLevel::Warning, "Próba rejestracji na istniejący email: " + email);
        return true;
    }
    return false;
}

bool RegisterModel::registerUser(const std::string& name, const std::string& surname, const std::string& email, const std::string& password) {
    errors.clear();

    // INFO: Wstawianie nowego użytkownika
    // TODO: W przyszłości warto dodać hashownaie hasła przed zapisem do bazy
    std::string sql = "INSERT INTO users (name, surname, email, password) VALUES ('" + 
                      name + "', '" + surname + "', '" + email + "', '" + password + "');";
    
    conn->executeQuery(sql);
    
    // Zakładamy sukces, jeśli executeQuery nie rzuciło błędu (choć Twoja klasa Database mogłaby zwracać bool)
    logger->log(LogLevel::Info, "Zarejestrowano nowego użytkownika: " + email);
    return true;
}

std::vector<std::string> RegisterModel::getErrors() {
    std::vector<std::string> tmp = errors;
    errors.clear();
    return tmp;
}
