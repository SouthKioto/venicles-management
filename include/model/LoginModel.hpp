#ifndef LOGIN_MODEL_HPP
#define LOGIN_MODEL_HPP

#include "../include/database/Database.hpp"
#include "./classes/User.hpp"
#include <string>

/**
 * @class LoginModel
 * @brief Odpowiada za logowanie uzytkownika
 */
class LoginModel {

private:
  User *user;

public:
  /**
   * @brief Ustawia nowe imie
   * @details Funkcja nie zwraca wartości, przyjmuje parametry typu std::string
   * name
   * @param name Nowe imie usera
   */
  void setUserData(User *user);
  bool checkUserExist(Database *database);
  bool checkPassword(Database *database);
};

#endif // !LOGIN_MODEL_HPP
