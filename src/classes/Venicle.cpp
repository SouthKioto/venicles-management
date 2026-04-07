#include "../../include/classes/Venicle.hpp"

Venicle::Venicle() : id(0), make(""), model(""), plate(""), year(0) {}

Venicle::Venicle(std::string make, std::string model, std::string plate, int year)
    : id(0), make(std::move(make)), model(std::move(model)), plate(std::move(plate)), year(year) {}

Venicle::~Venicle() {}

void Venicle::setId(int id) { this->id = id; }
void Venicle::setMake(std::string make) { this->make = std::move(make); }
void Venicle::setModel(std::string model) { this->model = std::move(model); }
void Venicle::setPlate(std::string plate) { this->plate = std::move(plate); }
void Venicle::setYear(int year) { this->year = year; }

int Venicle::getId() const { return id; }
std::string Venicle::getMake() const { return make; }
std::string Venicle::getModel() const { return model; }
std::string Venicle::getPlate() const { return plate; }
int Venicle::getYear() const { return year; }
