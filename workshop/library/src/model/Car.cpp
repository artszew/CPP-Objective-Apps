#include "../../library/include/model/Car.h"
#include "../../library/include/model/Vehicle.h"
#include "../../library/include/model/MotorVehicle.h"

Car::Car(const std::string& plateNumber, unsigned int basePrice, unsigned int engineDisplacement, SegmentType segment)
    : MotorVehicle(plateNumber, basePrice, engineDisplacement), segment(segment) {}

double Car::getActualRentalPrice() const {
    double segmentFactor = 1.0;
    switch (segment) {
        case SegmentType::A:
            break;
        case SegmentType::B:
            segmentFactor = 1.1;
            break;
        case SegmentType::C:
            segmentFactor = 1.2;
            break;
        case SegmentType::D:
            segmentFactor = 1.3;
            break;
        case SegmentType::E:
            segmentFactor = 1.5;
            break;
    }
    return MotorVehicle::getActualRentalPrice() * segmentFactor;
}

SegmentType Car::getSegment() {
    return segment;
}

std::string Car::segmentTypeToString(SegmentType segment) {
    switch(segment) {
        case SegmentType::A:
            return "A";
        case SegmentType::B:
            return "B";
        case SegmentType::C:
            return "C";
        case SegmentType::D:
            return "D";
        case SegmentType::E:
            return "E";
        default:
            return "Unknown";
    }
}

std::string Car::getInfo() const {
    std::string info = MotorVehicle::getInfo();
    info += ", type: Car, segment: " + segmentTypeToString(segment);  
    info += ", engine displacement: " + std::to_string(MotorVehicle::getEngineDisplacement());
    return info;
}

Car::~Car() {}

