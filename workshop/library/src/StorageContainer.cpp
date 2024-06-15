// src/repositories/StorageContainer.cpp
#include "../../library/include/StorageContainer.h"
#include "../../library/include/model/Client.h"
#include "../../library/include/model/Vehicle.h"
#include "../../library/include/model/Address.h"
#include "../../library/include/model/Rent.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
/**
 * @brief Konstruktor klasy StorageContainer. Inicjalizuje repozytoria przykładowymi danymi.
 */
StorageContainer::StorageContainer() {
    initializeTestData();
}

/**
 * @brief Zwraca referencję do repozytorium klientów.
 * @return Referencja do repozytorium klientów.
 */
ClientRepository& StorageContainer::getClientRepository() {
    return clientRepo;
}

/**
 * @brief Zwraca referencję do repozytorium pojazdów.
 * @return Referencja do repozytorium pojazdów.
 */
VehicleRepository& StorageContainer::getVehicleRepository() {
    return vehicleRepo;
}

/**
 * @brief Zwraca referencję do repozytorium wypożyczeń.
 * @return Referencja do repozytorium wypożyczeń.
 */
RentRepository& StorageContainer::getRentRepository() {
    return rentRepo;
}

/**
 * @brief Inicjalizuje repozytoria przykładowymi danymi.
 */
void StorageContainer::initializeTestData() {
    AddressPtr address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    ClientPtr client = std::make_shared<Client>("Jan", "Kowal", "1", address, std::make_shared<Default>());
    clientRepo.add(client);

    VehiclePtr vehicle = std::make_shared<Vehicle>("EL 21B15", 10);
    vehicleRepo.add(vehicle);

    pt::ptime now = boost::posix_time::second_clock::local_time();
    RentPtr rent = std::make_shared<Rent>(1, now, now + boost::posix_time::hours(24), client, vehicle);
    rentRepo.add(rent);

    // Dodaj ręcznie wypożyczenie do listy bieżących wypożyczeń klienta
    client->addRent(rent);
}



