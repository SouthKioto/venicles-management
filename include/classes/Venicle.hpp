#ifndef VENICLE_HPP
#define VENICLE_HPP

#include "../nlohmann/json.hpp"
#include <string>

class Venicle {
private:
  int id;
  std::string make;
  std::string model;
  std::string plate;
  int year;

public:
  Venicle();
  Venicle(std::string make, std::string model, std::string plate, int year);
  virtual ~Venicle();

  void setId(int id);
  void setMake(std::string make);
  void setModel(std::string model);
  void setPlate(std::string plate);
  void setYear(int year);

  int getId() const;
  std::string getMake() const;
  std::string getModel() const;
  std::string getPlate() const;
  int getYear() const;

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Venicle, id, make, model, plate, year);
};

#endif // VENICLE_HPP
