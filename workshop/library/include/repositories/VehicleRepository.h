// include/repositories/VehicleRepository.h
#ifndef VEHICLEREPOSITORY_H
#define VEHICLEREPOSITORY_H

#include <vector>
#include <string>
#include "../../library/include/typedefs.h"

class VehicleRepository {
private:
    std::vector<VehiclePtr> vehicles;
public:
    VehiclePtr get(size_t index) const;
    void add(const VehiclePtr& vehicle);
    void remove(const VehiclePtr& vehicle);
    std::string report() const;
    size_t size() const;
    std::vector<VehiclePtr> findBy(VehiclePredicate predicate) const;
    std::vector<VehiclePtr> findAll () const;
};

#endif // VEHICLEREPOSITORY_H

