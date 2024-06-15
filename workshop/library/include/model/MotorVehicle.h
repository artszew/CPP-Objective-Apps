#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

#include "Vehicle.h"

class MotorVehicle : public Vehicle {
private:
    unsigned int engineDisplacement;

public:
    MotorVehicle(const std::string& plateNumber, unsigned int basePrice, unsigned int engineDisplacement);
    unsigned int getEngineDisplacement() const;
    virtual double getActualRentalPrice() const override;
    virtual ~MotorVehicle();
    std::string getInfo() const;
};

#endif // MOTORVEHICLE_H

