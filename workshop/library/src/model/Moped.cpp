#include "../../library/include/model/Moped.h"
#include "../../library/include/model/Vehicle.h"
#include "../../library/include/model/MotorVehicle.h"
Moped::Moped(const std::string& plateNumber, unsigned int basePrice, unsigned int engineDisplacement)
    : MotorVehicle(plateNumber, basePrice, engineDisplacement) {}

double Moped::getActualRentalPrice() const {
    return MotorVehicle::getActualRentalPrice();
}

std::string Moped::getInfo() const {
    std::string info = MotorVehicle::getInfo(); 
    info += ", type: Moped";
    return info;
}


Moped::~Moped() {}

