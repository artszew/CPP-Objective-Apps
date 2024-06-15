#ifndef BICYCLE_H
#define BICYCLE_H

#include "Vehicle.h"

class Bicycle : public Vehicle {
public:
    Bicycle(const std::string& plateNumber, unsigned int basePrice);
    virtual double getActualRentalPrice() const override;
    virtual ~Bicycle();
    std::string getInfo() const;
};

#endif // BICYCLE_H

