#ifndef REGISTER_MODEL_HPP
#define REGISTER_MODEL_HPP

#include "./classes/User.hpp"

class RegisterModel {
private:
  User *user;

public:
  void setUser(User *user);
};

#endif // !REGISTER_MODEL_HPP
