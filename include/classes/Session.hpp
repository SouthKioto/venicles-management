#ifndef SESSION_HPP
#define SESSION_HPP

#include <iostream>

class Session {
private:
  Session();
  int userId = -1;
  std::string email = "";
  bool isLoggedIn = false;

public:
  static Session &getInstance();
  void login(int &userId, std::string &email);
  void logout();

  bool isLogged() const;
  std::string getEmail() const;
  int getUserId() const;
};

#endif // !SESSION_HPP
