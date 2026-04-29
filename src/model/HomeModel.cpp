#include "../include/model/HomeModel.hpp"

HomeModel::HomeModel(Database *conn, Logger *logger)
    : conn(conn), logger(logger) {}

int HomeModel::getVehicleCount() {
  return static_cast<int>(getVehicles().size());
}

std::vector<VehicleSummary> HomeModel::getVehicles() {
  auto mapVehicle = [](sqlite3_stmt *stmt) -> VehicleSummary {
    VehicleSummary vehicle;
    vehicle.brand = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
    vehicle.model = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
    vehicle.year = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));
    vehicle.color = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3));
    return vehicle;
  };

  std::vector<VehicleSummary> vehicles = conn->fetch<VehicleSummary>(
      "SELECT brand, model, year, color FROM vehicle ORDER BY id;", mapVehicle);

  if (vehicles.empty()) {
    logger->log(LogLevel::Warning, "Brak aut w tabeli vehicle");
  }

  return vehicles;
}
