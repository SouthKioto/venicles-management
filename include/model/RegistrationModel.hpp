#ifndef REGISTRATION_MODEL_HPP
#define REGISTRATION_MODEL_HPP

#include "../classes/User.hpp"
#include "../classes/Venicle.hpp"
#include "../database/SQLiteDatabase.hpp"
#include <vector>

class RegistrationModel {
private:
  SQLiteDatabase *db;

public:
  explicit RegistrationModel(SQLiteDatabase *db);
  ~RegistrationModel();

  bool registerUser(const User &user);
  std::vector<Venicle> getVehicleList();
};

#endif // REGISTRATION_MODEL_HPP
