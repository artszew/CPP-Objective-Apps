#include "../../library/include/model/MotorVehicle.h"
#include "../../library/include/model/Vehicle.h"
MotorVehicle::MotorVehicle(const std::string& plateNumber, unsigned int basePrice, unsigned int engineDisplacement)
    : Vehicle(plateNumber, basePrice), engineDisplacement(engineDisplacement) {}

unsigned int MotorVehicle::getEngineDisplacement() const {
    return engineDisplacement;
}

double MotorVehicle::getActualRentalPrice() const {
    double factor = 1.0;
    if (engineDisplacement < 1000) {
        factor = 1.0;
    } else if (engineDisplacement <= 2000) {
        factor = 1.0 + 0.5 * (static_cast<double>(engineDisplacement) - 1000) / 1000;
    } else {
        factor = 1.5;
    }
    return getBasePrice() * factor;
    }
    
std::string MotorVehicle::getInfo() const {
	std::string info = Vehicle::getInfo();
	info += ", type: Motor Vehicle";
	info += ", engine displacement: " + std::to_string(engineDisplacement); 
    return info; 
}

    
    
    MotorVehicle::~MotorVehicle() {}
