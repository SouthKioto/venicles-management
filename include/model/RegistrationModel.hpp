#ifndef REGISTRATION_MODEL_HPP
#define REGISTRATION_MODEL_HPP

#include "./classes/User.hpp"
#include <string>

/**
 * @class RegistrationModel
 * @brief Odpowiada za rejestracje nowego uzytkownika
 */
class RegistrationModel
{

private:
  User *user;

public:
  /**
   * @brief Konstruktor domyslny
   */
  RegistrationModel();

  /**
   * @brief Destruktor
   */
  ~RegistrationModel();

  /**
   * @brief Rejestruje nowego uzytkownika
   * @details Funkcja przyjmuje parametry potrzebne do utworzenia konta
   * @param name Imie uzytkownika
   * @param surname Nazwisko uzytkownika
   * @param email Adres email uzytkownika
   * @param password Haslo uzytkownika
   * @return Zwraca true jesli rejestracja powiodla sie, false w przeciwnym
   * wypadku
   */
  bool registerUser(std::string name, std::string surname, std::string email,
                    std::string password);

  /**
   * @brief Sprawdza czy email jest juz zarejestrowany
   * @param email Adres email do sprawdzenia
   * @return Zwraca true jesli email istnieje, false w przeciwnym wypadku
   */
  bool emailExists(std::string email);

  /**
   * @brief Waliduje poprawnosc danych rejestracji
   * @param name Imie uzytkownika
   * @param surname Nazwisko uzytkownika
   * @param email Adres email uzytkownika
   * @param password Haslo uzytkownika
   * @return Zwraca true jesli dane sa poprawne, false w przeciwnym wypadku
   */
  bool validateRegistrationData(std::string name, std::string surname,
                                std::string email, std::string password);
};

#endif // !REGISTRATION_MODEL_HPP
