#include <boost/test/unit_test.hpp>
#include "../include/StorageContainer.h"
#include "../include/model/Client.h"
#include "../include/model/Vehicle.h"
#include "../include/model/Rent.h"
#include "../include/typedefs.h"
#include <memory>

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(RepositoryTests)

/**
 * @brief Test sprawdzający poprawność dodawania i usuwania klientów z repozytorium.
 */
BOOST_AUTO_TEST_CASE(ClientRepositoryTest) {
    StorageContainer storage;

    // Dodanie nowego klienta
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto newClient = std::make_shared<Client>("Jan", "Kowal", "1", address, std::make_shared<Default>());
    storage.getClientRepository().add(newClient);

    // Sprawdzenie wielkości repozytorium po dodaniu klienta
    BOOST_CHECK_EQUAL(storage.getClientRepository().size(), 2);

    // Usunięcie klienta
    storage.getClientRepository().remove(newClient);
    // Sprawdzenie wielkości repozytorium po usunięciu klienta
    BOOST_CHECK_EQUAL(storage.getClientRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność dodawania i usuwania pojazdów z repozytorium.
 */
BOOST_AUTO_TEST_CASE(VehicleRepositoryTest) {
    StorageContainer storage;

    // Dodanie nowego pojazdu
    auto newVehicle = std::make_shared<Vehicle>("EL 21B15", 10);
    storage.getVehicleRepository().add(newVehicle);

    // Sprawdzenie wielkości repozytorium po dodaniu pojazdu
    BOOST_CHECK_EQUAL(storage.getVehicleRepository().size(), 2);

    // Usunięcie pojazdu
    storage.getVehicleRepository().remove(newVehicle);
    // Sprawdzenie wielkości repozytorium po usunięciu pojazdu
    BOOST_CHECK_EQUAL(storage.getVehicleRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność dodawania i usuwania wypożyczeń z repozytorium.
 */
BOOST_AUTO_TEST_CASE(RentRepositoryTest) {
    StorageContainer storage;

    auto client = storage.getClientRepository().get(0);
    auto vehicle = storage.getVehicleRepository().get(0);
    pt::ptime now = boost::posix_time::second_clock::local_time();
    auto newRent = std::make_shared<Rent>(1, now, now + boost::posix_time::hours(24), client, vehicle);
    storage.getRentRepository().add(newRent);

    // Sprawdzenie wielkości repozytorium po dodaniu wypożyczenia
    BOOST_CHECK_EQUAL(storage.getRentRepository().size(), 2);

    // Usunięcie wypożyczenia
    storage.getRentRepository().remove(newRent);
    // Sprawdzenie wielkości repozytorium po usunięciu wypożyczenia
    BOOST_CHECK_EQUAL(storage.getRentRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność obsługi usuwania nieistniejącego klienta.
 */
BOOST_AUTO_TEST_CASE(RemoveNonExistentClientTest) {
    StorageContainer storage;

    // Próba usunięcia nieistniejącego klienta
    storage.getClientRepository().remove(nullptr);

    // Sprawdzenie, czy wielkość repozytorium pozostała bez zmian
    BOOST_CHECK_EQUAL(storage.getClientRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność obsługi usuwania nieistniejącego pojazdu.
 */
BOOST_AUTO_TEST_CASE(RemoveNonexistentVehicleTest) {
    StorageContainer storage;

    // Próba usunięcia nieistniejącego pojazdu
    storage.getVehicleRepository().remove(nullptr);

    // Sprawdzenie, czy wielkość repozytorium pozostała bez zmian
    BOOST_CHECK_EQUAL(storage.getVehicleRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność obsługi usuwania nieistniejącego wypożyczenia.
 */
BOOST_AUTO_TEST_CASE(RemoveNonexistentRentTest) {
    StorageContainer storage;

    // Próba usunięcia nieistniejącego wypożyczenia
    storage.getRentRepository().remove(nullptr);

    // Sprawdzenie, czy wielkość repozytorium pozostała bez zmian
    BOOST_CHECK_EQUAL(storage.getRentRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność obsługi dodawania pustego wskaźnika klienta.
 */
BOOST_AUTO_TEST_CASE(AddNullClientTest) {
    StorageContainer storage;

    // Próba dodania pustego wskaźnika
    storage.getClientRepository().add(nullptr);

    // Sprawdzenie, czy wielkość repozytorium pozostała bez zmian
    BOOST_CHECK_EQUAL(storage.getClientRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność obsługi dodawania pustego wskaźnika pojazdu.
 */
BOOST_AUTO_TEST_CASE(AddNullVehicleTest) {
    StorageContainer storage;

    // Próba dodania pustego wskaźnika
    storage.getVehicleRepository().add(nullptr);

    // Sprawdzenie, czy wielkość repozytorium pozostała bez zmian
    BOOST_CHECK_EQUAL(storage.getVehicleRepository().size(), 1);
}

/**
 * @brief Test sprawdzający poprawność obsługi dodawania pustego wskaźnika wypożyczenia.
 */
BOOST_AUTO_TEST_CASE(AddNullRentTest) {
    StorageContainer storage;

    // Próba dodania pustego wskaźnika
    storage.getRentRepository().add(nullptr);

    // Sprawdzenie, czy wielkość repozytorium pozostała bez zmian
    BOOST_CHECK_EQUAL(storage.getRentRepository().size(), 1);
}

BOOST_AUTO_TEST_SUITE_END()

//Proste funkcje logiczne pomagające w testach repozytoriów
bool clientHasLastNameKowal(const ClientPtr& client) {
    return client->getLastName() == "Kowal";
}
bool vehicleHasPlateNumberEL21B15(const VehiclePtr& vehicle) {
    return vehicle->getPlateNumber() == "EL 21B15";
}
bool rentHasID1(const RentPtr& rent) {
    return rent->getId() == 1;
}

BOOST_AUTO_TEST_SUITE(RepositoriesPredicatesTests)

// Test dla metody findBy w repozytorium klientów
BOOST_AUTO_TEST_CASE(FindByClientTest) {
    StorageContainer storage;

    // Wywołanie metody findBy z wybranym predykatem
    std::vector<ClientPtr> foundClients = storage.getClientRepository().findBy(clientHasLastNameKowal);

    // Sprawdzenie, czy liczba znalezionych klientów jest poprawna
    BOOST_CHECK_EQUAL(foundClients.size(), 1); // Zakładając, że jest tylko 1 klient o nazwisku "Kowal"
}

// Test dla metody findBy w repozytorium pojazdów
BOOST_AUTO_TEST_CASE(FindByVehicleTest) {
    StorageContainer storage;

    // Wywołanie metody findBy z wybranym predykatem
    std::vector<VehiclePtr> foundVehicles = storage.getVehicleRepository().findBy(vehicleHasPlateNumberEL21B15);

    // Sprawdzenie, czy liczba znalezionych pojazdów jest poprawna
    BOOST_CHECK_EQUAL(foundVehicles.size(), 1); 
}

// Test dla metody findBy w repozytorium wypożyczeń
BOOST_AUTO_TEST_CASE(FindByRentTest) {
    StorageContainer storage;

    // Wywołanie metody findBy z wybranym predykatem
    std::vector<RentPtr> foundRents = storage.getRentRepository().findBy(rentHasID1);

    // Sprawdzenie, czy liczba znalezionych wypozyczen jest poprawna
    BOOST_CHECK_EQUAL(foundRents.size(), 1); 
}

BOOST_AUTO_TEST_SUITE_END()

