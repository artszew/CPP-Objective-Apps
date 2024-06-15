//Introduction project.

#include <iostream>
//headers:
#include "../../library/include/model/Address.h"
#include "../../library/include/model/Bicycle.h"
#include "../../library/include/model/Car.h"
#include "../../library/include/model/Client.h"
#include "../../library/include/model/ClientType.h"
#include "../../library/include/model/Moped.h"
#include "../../library/include/model/MotorVehicle.h"
#include "../../library/include/model/Rent.h"
#include "../../library/include/model/Vehicle.h"
#include "../../library/include/StorageContainer.h"
#include "../../library/include/typedefs.h"


int main()
{
    pt::ptime now = boost::posix_time::second_clock::local_time();

    StorageContainer storage;
    storage.initializeTestData();

    std::cout << storage.getClientRepository().report() << std::endl;
    std::cout << storage.getVehicleRepository().report() << std::endl;
    std::cout << storage.getRentRepository().report() << std::endl;

    ClientPtr client = storage.getClientRepository().get(0);
    VehiclePtr vehicle = storage.getVehicleRepository().get(0);
    RentPtr newRent = std::make_shared<Rent>(2, now, now + boost::posix_time::hours(24), client, vehicle);
    storage.getRentRepository().add(newRent);

    // Dodaj ręcznie wypożyczenie do listy bieżących wypożyczeń klienta
    client->addRent(newRent);

    std::cout << storage.getClientRepository().report() << std::endl;
    std::cout << storage.getVehicleRepository().report() << std::endl;
    std::cout << storage.getRentRepository().report() << std::endl;

    return 0;
}

