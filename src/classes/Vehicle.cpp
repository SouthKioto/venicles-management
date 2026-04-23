#include "../../include/classes/Vehicle.hpp"

// Konstruktor
Vehicle::Vehicle(std::string brand, std::string model, std::string year,
                 std::string color, std::string licensePlate, std::string vin,
                 User owner)
    : brand(brand), model(model), year(year), color(color),
      licensePlate(licensePlate), vin(vin), owner(owner) {}

Vehicle::Vehicle() {};

Vehicle::~Vehicle() {}

// --- Settery ---

void Vehicle::setId(int id) { this->id = id; };

void Vehicle::setBrand(std::string brand) { this->brand = brand; }

void Vehicle::setModel(std::string model) { this->model = model; }

void Vehicle::setYear(std::string year) { this->year = year; }

void Vehicle::setColor(std::string color) { this->color = color; }

void Vehicle::setLicensePlate(std::string licensePlate) {
  this->licensePlate = licensePlate;
}

void Vehicle::setVin(std::string vin) { this->vin = vin; }

void Vehicle::setOwner(User owner) { this->owner = owner; }

// --- Gettery ---
int Vehicle::getId() const { return this->id; }

std::string Vehicle::getBrand() const { return this->brand; }

std::string Vehicle::getModel() const { return this->model; }

std::string Vehicle::getYear() const { return this->year; }

std::string Vehicle::getColor() const { return this->color; }

std::string Vehicle::getLicensePlate() const { return this->licensePlate; }

std::string Vehicle::getVin() const { return this->vin; }

User Vehicle::getOwner() const { return this->owner; }
