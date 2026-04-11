#ifndef VEHICLE_MODEL_HPP
#define VEHICLE_MODEL_HPP

#include "../classes/Vehicle.hpp"
#include <string>

/**
 * @class VehicleModel
 * @brief Odpowiada za rejestracje i zarzadzanie pojazdami
 */
class VehicleModel {

private:
  Vehicle *vehicle;

public:
  /**
   * @brief Ustawia nowy pojazd
   * @details Funkcja nie zwraca wartości, przyjmuje wskaźnik na Vehicle
   * @param vehicle Nowy pojazd
   */
  void setVehicle(Vehicle *vehicle);

  /**
   * @brief Zwraca aktualny pojazd
   * @return Wskaźnik na aktualny pojazd
   */
  Vehicle *getVehicle() const;

  /**
   * @brief Czyści dane pojazdu
   */
  void clearVehicle();
};

#endif // !VEHICLE_MODEL_HPP
