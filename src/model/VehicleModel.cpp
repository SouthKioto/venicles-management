#include "../include/model/VehicleModel.hpp"

void VehicleModel::setVehicle(Vehicle *vehicle) { this->vehicle = vehicle; }

Vehicle *VehicleModel::getVehicle() const { return vehicle; }

void VehicleModel::clearVehicle() { this->vehicle = nullptr; }
