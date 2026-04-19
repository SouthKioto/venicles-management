#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include "User.hpp" // Zakładam, że User.hpp jest w tym samym folderze
#include <string>

class Vehicle {
private:
  int id;
  std::string make;
  std::string model;
  std::string year;
  std::string color;
  std::string licensePlate;
  std::string vin;
  User owner;

public:
  Vehicle(std::string make, std::string model, std::string year,
          std::string color, std::string licensePlate, std::string vin,
          User owner);

  Vehicle();

  virtual ~Vehicle();

  // info: settery
  void setId(int id);
  void setMake(std::string make);
  void setBrand(std::string brand);
  void setModel(std::string model);
  void setYear(std::string year);
  void setColor(std::string color);
  void setLicensePlate(std::string licensePlate);
  void setVin(std::string vin);
  void setOwner(User owner);

  // info: gettery
  int getId() const;
  std::string getMake() const;
  std::string getBrand() const;
  std::string getModel() const;
  std::string getYear() const;
  std::string getColor() const;
  std::string getLicensePlate() const;
  std::string getVin() const;
  User getOwner() const;
};

#endif // VEHICLE_HPP
