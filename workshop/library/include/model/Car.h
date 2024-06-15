#ifndef CAR_H
#define CAR_H

#include "MotorVehicle.h"

enum class SegmentType { A, B, C, D, E };

class Car : public MotorVehicle {
private:
    SegmentType segment;

public:
    Car(const std::string& plateNumber, unsigned int basePrice, unsigned int engineDisplacement, SegmentType segment);
    virtual double getActualRentalPrice() const override;
    virtual ~Car();
    std::string getInfo() const;
    static std::string segmentTypeToString(SegmentType segment);
    SegmentType getSegment(); 
};

#endif // CAR_H

