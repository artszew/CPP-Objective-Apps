#include "../../library/include/model/Bicycle.h"
#include "../../library/include/model/Vehicle.h"
Bicycle::Bicycle(const std::string& plateNumber, unsigned int basePrice)
    : Vehicle(plateNumber, basePrice) {}
    
double Bicycle::getActualRentalPrice() const {
    return getBasePrice();
}   
std::string Bicycle::getInfo() const {
    std::string info = Vehicle::getInfo(); 
    info += ", type: Bicycle";
    return info; // 
}
    
    
Bicycle::~Bicycle() {}

