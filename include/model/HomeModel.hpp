#ifndef HOMEMODEL_HPP
#define HOMEMODEL_HPP

#include "../include/additionalScripts/Logger.hpp"
#include "../include/database/Database.hpp"
#include <string>
#include <vector>

struct VehicleSummary {
	std::string brand;
	std::string model;
	std::string year;
	std::string color;
};

class HomeModel {
private:
	Database *conn;
	Logger *logger;

public:
	HomeModel(Database *conn, Logger *logger);
	int getVehicleCount();
	std::vector<VehicleSummary> getVehicles();
};

#endif // !HOMEMODEL_HPP
