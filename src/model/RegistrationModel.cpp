#include "../../include/model/RegistrationModel.hpp"

RegistrationModel::RegistrationModel(SQLiteDatabase *db) : db(db) {}

RegistrationModel::~RegistrationModel() {}

bool RegistrationModel::registerUser(const User &user) {
  if (db == nullptr) {
    return false;
  }

  return db->insertUser(user);
}

std::vector<Venicle> RegistrationModel::getVehicleList() {
  if (db == nullptr) {
    return {};
  }
  return db->getAllVehicles();
}
