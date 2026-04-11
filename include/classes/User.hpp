#ifndef USER_HPP
#define USER_HPP

#include "../nlohmann/json.hpp"
#include <iostream>

class User {
private:
  std::string name;
  std::string surname;
  std::string email;
  std::string password;
  int age;

public:
  User(std::string name, std::string surname, std::string email,
       std::string password, int age);

  virtual ~User();

  // info: settery
  void setName(std::string name);

  void setSurname(std::string surname);

  void setEmail(std::string email);

  void setPassword(std::string password);

  void setAge(int age);

  // info: gettery
  std::string getName() const;

  std::string getSurname() const;

  std::string getEmail() const;

  std::string getPassword() const;

  int getAge() const;

};

#endif // !USER_HPP
