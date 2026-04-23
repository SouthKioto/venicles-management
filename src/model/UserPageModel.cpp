#include "../include/model/UserPageModel.hpp"

UserPageModel::UserPageModel(User *user, Router *router, Database *database,
                             Logger *logger)
    : user(user), router(router), database(database), logger(logger) {}

User *UserPageModel::getUserData() { return this->user; }

bool UserPageModel::checkAdmin() {
  this->isAdmin = user->getAdminPermission();
  return this->isAdmin;
}

bool UserPageModel::showAdminSettings() {
  if (!user->getAdminPermission()) {
    logger->log(LogLevel::Info, "No access");
    return false;
  }

  logger->log(LogLevel::Info,
              "User " + user->getEmail() + " jest administratorem");
  return true;
}

std::vector<Vehicle> UserPageModel::getUserVehicles() {
  std::vector<Vehicle> vehicles;

  std::string userId = std::to_string(user->getId());

  auto mapToVehicle = [](sqlite3_stmt *stmt) -> Vehicle {
    Vehicle vehicle;
    vehicle.setId((const int)sqlite3_column_int(stmt, 0));
    vehicle.setBrand((const char *)sqlite3_column_text(stmt, 1));
    vehicle.setModel((const char *)sqlite3_column_text(stmt, 2));
    vehicle.setYear((const char *)sqlite3_column_text(stmt, 3));
    vehicle.setColor((const char *)sqlite3_column_text(stmt, 4));

    return vehicle;
  };

  // WARNING: NIE RUSZAĆ
  std::string sql =
      "SELECT vehicle.id, vehicle.brand, vehicle.model, vehicle.year, "
      "vehicle.color FROM userVehicle"
      "JOIN users ON userVehicle.idUser = users.id"
      "JOIN vehicle ON userVehicle.idVehicle = vehicle.id"
      "WHERE users.id = " +
      userId + ";";

  vehicles = database->fetch<Vehicle>(sql, mapToVehicle);

  if (vehicles.empty()) {
    logger->log(LogLevel::Warning, "Dane nie zostały pobrane");
  }

  for (Vehicle vehicle : vehicles) {
    std::cout << vehicle.getModel() << std::endl;
  }

  return vehicles;
}
