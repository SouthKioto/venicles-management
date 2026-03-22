#include "../../include/classes/User.hpp"

User::User(std::string name, std::string surname, std::string email,
           std::string password, int age)
    : name(name), surname(surname), email(email), password(password), age(age) {
}

User::~User() {}

void User::setName(std::string name) { this->name = name; }

void User::setSurname(std::string surname) { this->surname = surname; }

void User::setEmail(std::string email) { this->email = email; }

void User::setPassword(std::string password) { this->password = password; }

void User::setAge(int age) { this->age = age; }

std::string User::getName() const { return name; }

std::string User::getSurname() const { return surname; }

std::string User::getEmail() const { return email; }

std::string User::getPassword() const { return password; }

int User::getAge() const { return age; }
