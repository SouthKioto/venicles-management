#include "../../include/classes/Vehicle.hpp"

// Konstruktor
Vehicle::Vehicle(std::string make, std::string model, int year,
                 std::string color, std::string licensePlate, std::string vin,
                 User owner)
    : make(make), model(model), year(year), color(color),
      licensePlate(licensePlate), vin(vin), owner(owner) {}

Vehicle::~Vehicle() {}

// --- Settery ---

void Vehicle::setMake(std::string make) { 
    this->make = make; 
}

void Vehicle::setModel(std::string model) { 
    this->model = model; 
}

void Vehicle::setYear(int year) { 
    this->year = year; 
}

void Vehicle::setColor(std::string color) { 
    this->color = color; 
}

void Vehicle::setLicensePlate(std::string licensePlate) {
    this->licensePlate = licensePlate;
}

void Vehicle::setVin(std::string vin) { 
    this->vin = vin; 
}

void Vehicle::setOwner(User owner) { 
    this->owner = owner; 
}

// --- Gettery ---

std::string Vehicle::getMake() const { 
    return make; 
}

std::string Vehicle::getModel() const { 
    return model; 
}

int Vehicle::getYear() const { 
    return year; 
}

std::string Vehicle::getColor() const { 
    return color; 
}

std::string Vehicle::getLicensePlate() const { 
    return licensePlate; 
}

std::string Vehicle::getVin() const { 
    return vin; 
}

User Vehicle::getOwner() const { 
    return owner; 
}