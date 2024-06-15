#ifndef MOPED_H
#define MOPED_H

#include "MotorVehicle.h"

class Moped : public MotorVehicle {
public:
    Moped(const std::string& plateNumber, unsigned int basePrice, unsigned int engineDisplacement);
    virtual double getActualRentalPrice() const override;
    virtual ~Moped();
    std::string getInfo() const;
};

#endif // MOPED_H

