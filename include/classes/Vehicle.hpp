#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>
#include "User.hpp"

class Vehicle {
private:
    std::string make;
    std::string model;
    int year;
    std::string color;
    std::string licensePlate;
    std::string vin;
    User owner;

public:
    Vehicle(std::string make, std::string model, int year, std::string color,
            std::string licensePlate, std::string vin, User owner);

    virtual ~Vehicle();

    // info: settery
    void setMake(std::string make);
    void setModel(std::string model);
    void setYear(int year);
    void setColor(std::string color);
    void setLicensePlate(std::string licensePlate);
    void setVin(std::string vin);
    void setOwner(User owner);

    // info: gettery
    std::string getMake() const;
    std::string getModel() const;
    int getYear() const;
    std::string getColor() const;
    std::string getLicensePlate() const;
    std::string getVin() const;
    User getOwner() const;
};

#endif // VEHICLE_HPP