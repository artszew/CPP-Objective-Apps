// include/repositories/StorageContainer.h
#ifndef STORAGECONTAINER_H
#define STORAGECONTAINER_H

#include "repositories/ClientRepository.h"
#include "repositories/VehicleRepository.h"
#include "repositories/RentRepository.h"
#include "../../library/include/model/Client.h"
#include "../../library/include/model/Vehicle.h"
#include "../../library/include/model/Address.h"
#include "../../library/include/model/Rent.h"

class StorageContainer {
private:
    ClientRepository clientRepo;
    VehicleRepository vehicleRepo;
    RentRepository rentRepo;

public:
    StorageContainer();
    ClientRepository& getClientRepository();
    VehicleRepository& getVehicleRepository();
    RentRepository& getRentRepository();
    void initializeTestData();
};

#endif // STORAGECONTAINER_H

