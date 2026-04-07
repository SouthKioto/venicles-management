#include "../../include/classes/User.hpp"

User::User() : id(0), name(""), surname(""), email(""), password(""), age(0) {}

User::User(std::string name, std::string surname, std::string email,
           std::string password, int age)
    : id(0), name(std::move(name)), surname(std::move(surname)),
      email(std::move(email)), password(std::move(password)), age(age) {}

User::User(int id, std::string name, std::string surname, std::string email,
           std::string password, int age)
    : id(id), name(std::move(name)), surname(std::move(surname)),
      email(std::move(email)), password(std::move(password)), age(age) {}

User::~User() {}

void User::setId(int id) { this->id = id; }
void User::setName(std::string name) { this->name = std::move(name); }
void User::setSurname(std::string surname) { this->surname = std::move(surname); }
void User::setEmail(std::string email) { this->email = std::move(email); }
void User::setPassword(std::string password) { this->password = std::move(password); }
void User::setAge(int age) { this->age = age; }

int User::getId() const { return id; }
std::string User::getName() const { return name; }
std::string User::getSurname() const { return surname; }
std::string User::getEmail() const { return email; }
std::string User::getPassword() const { return password; }
int User::getAge() const { return age; }
