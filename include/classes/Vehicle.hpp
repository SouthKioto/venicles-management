#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include "User.hpp" // Zakładam, że User.hpp jest w tym samym folderze
#include <string>

class Vehicle {
private:
  int id;
  std::string make;
  std::string model;
  int year;
  std::string color;
  std::string licensePlate;
  std::string vin;
  User owner; // Obiekt klasy User zamiast stringa

public:
  Vehicle(std::string make, std::string model, int year, std::string color,
          std::string licensePlate, std::string vin, User owner);

  Vehicle();

  virtual ~Vehicle();

  // info: settery
  void setId(int id);
  void setMake(std::string make);
  void setModel(std::string model);
  void setYear(int year);
  void setColor(std::string color);
  void setLicensePlate(std::string licensePlate);
  void setVin(std::string vin);
  void setOwner(User owner);

  // info: gettery
  int getId() const;
  std::string getMake() const;
  std::string getModel() const;
  int getYear() const;
  std::string getColor() const;
  std::string getLicensePlate() const;
  std::string getVin() const;
  User getOwner() const;
};

#endif // VEHICLE_HPP
