#include "../include/classes/Session.hpp"

Session::Session() {};

Session &Session::getInstance() {
  static Session instance;
  return instance;
};

void Session::login(int &userId, std::string &email) {
  this->userId = userId;
  this->email = email;
  this->isLoggedIn = true;
}

void Session::logout() {
  this->userId = -1;
  this->email = "";
  this->isLoggedIn = false;
}

bool Session::isLogged() const { return this->isLoggedIn; }

int Session::getUserId() const { return this->userId; }

std::string Session::getEmail() const { return this->email; }
