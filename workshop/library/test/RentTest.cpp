/**
 * @file RentTest.cpp
 * @brief Plik zawierający testy jednostkowe dla klasy Rent.
 */
#include <boost/test/unit_test.hpp>
#include <memory>
#include "../../library/include/typedefs.h"
#include <boost/date_time.hpp>
#include "../../library/include/StorageContainer.h"
#include "../../library/include/model/Rent.h"
#include "../../library/include/model/Vehicle.h"
#include "../../library/include/model/Client.h"
#include "../../library/include/model/ClientType.h"
#include "../../library/include/model/Address.h"

#include <vector>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;


BOOST_AUTO_TEST_SUITE(RentTests)

/**
 * @brief Przypadek do testowania metody endRent przy braku czasu zakończenia i czasie rozpoczęcia w przeszłości.
 */
BOOST_AUTO_TEST_CASE(TestEndRentNotSpecified) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time();
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    auto client = std::make_shared<Client>("Jan", "Kowal", "1234567890", address, clientType);
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    auto rent = std::make_shared<Rent>(1, beginTime, pt::not_a_date_time, client, vehicle);

    // Act
    rent->endRent(pt::not_a_date_time);

    // Assert
    BOOST_TEST(rent->getRentDays() == 0); // Brak zakończenia
}


/**
 * @brief Przypadek do testowania metody endRent przy braku czasu zakończenia i czasie rozpoczęcia w przeszłości.
 */
BOOST_AUTO_TEST_CASE(TestEndRentNotSpecifiedInPast) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time() - pt::seconds(1);
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    auto client = std::make_shared<Client>("Jan", "Kowal", "1234567890", address, clientType);
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    auto rent = std::make_shared<Rent>(1, beginTime, pt::not_a_date_time, client, vehicle);

    // Act
    rent->endRent(pt::not_a_date_time);

    // Assert
    BOOST_TEST(rent->getRentDays() == 0); // Brak zakończenia
}

/**
 * @brief Przypadek do testowania metody endRent przy podanym czasie zakończenia.
 */
BOOST_AUTO_TEST_CASE(TestEndRentSpecified) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time();
    pt::ptime endTime = beginTime + pt::hours(1);
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    auto client = std::make_shared<Client>("Jan", "Kowal", "1234567890", address, clientType);
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    auto rent = std::make_shared<Rent>(1, beginTime, pt::not_a_date_time, client, vehicle);

    // Act
    rent->endRent(endTime);

    // Assert
    BOOST_TEST(rent->getRentDays() == 1); // Sprawdzamy, czy dni wypożyczenia są poprawne
}

/**
 * @brief Przypadek do testowania metody endRent przy podanym czasie zakończenia w przeszłości.
 */
BOOST_AUTO_TEST_CASE(TestEndRentSpecifiedInPast) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time();
    pt::ptime endTime = beginTime - pt::hours(1);
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    auto client = std::make_shared<Client>("Jan", "Kowal", "1234567890", address, clientType);
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    auto rent = std::make_shared<Rent>(1, beginTime, pt::not_a_date_time, client, vehicle);

    // Act
    rent->endRent(endTime);

    // Assert
    BOOST_TEST(rent->getRentDays() == 0); // Sprawdzamy, czy dni wypożyczenia są poprawne
}

/**
 * @brief Przypadek do testowania metody getRentDays na wartościach granicznych.
 */
BOOST_AUTO_TEST_CASE(TestGetRentDaysBoundaryValues) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time();

    // Act & Assert
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    auto client = std::make_shared<Client>("Jan", "Kowal", "1234567890", address, clientType);
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    auto rent1 = std::make_shared<Rent>(1, beginTime, beginTime + pt::seconds(59), client, vehicle);
    rent1->endRent(beginTime + pt::seconds(59));
    BOOST_TEST(rent1->getRentDays() == 0);

    auto rent2 = std::make_shared<Rent>(2, beginTime, pt::not_a_date_time, client, vehicle);
    rent2->endRent(beginTime + pt::minutes(1));
    BOOST_TEST(rent2->getRentDays() == 1);

    auto rent3 = std::make_shared<Rent>(3, beginTime, pt::not_a_date_time, client, vehicle);
    rent3->endRent(beginTime + pt::hours(23) + pt::minutes(59));
    BOOST_TEST(rent3->getRentDays() == 1);

    auto rent4 = std::make_shared<Rent>(4, beginTime, pt::not_a_date_time, client, vehicle);
    rent4->endRent(beginTime + pt::hours(24));
    BOOST_TEST(rent4->getRentDays() == 2);

    auto rent5 = std::make_shared<Rent>(5, beginTime, pt::not_a_date_time, client, vehicle);
    rent5->endRent(beginTime + pt::hours(24) + pt::minutes(1));
    BOOST_TEST(rent5->getRentDays() == 2);
}

/**
 * @brief Przypadek do testowania metody getRentDays bez podanego czasu zakończenia.
 */
BOOST_AUTO_TEST_CASE(TestGetRentDaysNoEndTime) {
    // Arrange
    auto client = std::make_shared<Client>("Jan", "Kowal", "1234567890", nullptr, nullptr);
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    pt::ptime beginTime = pt::second_clock::local_time();
    auto rent = std::make_shared<Rent>(6, beginTime, pt::not_a_date_time, client, vehicle);

    // Act
    // (no action needed, as endTime is not specified)

    // Assert
    BOOST_TEST(rent->getRentDays() == 0);
}

/**
 * @brief Przypadek do testowania metody getRentCost bez podanego pojazdu.
 */
BOOST_AUTO_TEST_CASE(TestGetRentCost) {
    // Arrange
    auto client = std::make_shared<Client>("Jan", "Kowal", "1234567890", nullptr, nullptr);
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    Rent rent(7, pt::second_clock::local_time(), pt::not_a_date_time, client, vehicle);

    // Act
    int cost = rent.getRentCost();

    // Assert
    BOOST_TEST(cost == 0);
}

/**
 * @brief Przypadek do testowania metody getInfo.
 */
BOOST_AUTO_TEST_CASE(TestGetInfo) {
    // Arrange
    auto client = std::make_shared<Client>("Jan", "Kowal", "1234567890", nullptr, nullptr);
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    Rent rent(8, pt::second_clock::local_time(), pt::not_a_date_time, client, vehicle);

    // Act
    std::string info = rent.getInfo();

    // Assert
    BOOST_TEST(!info.empty());
}

/**
 * @brief Przypadek do testowania metody getRentCost przy braku dni wypożyczenia.
 */
BOOST_AUTO_TEST_CASE(TestGetRentCostZeroDays) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time();
    auto client = std::make_shared<Client>("Jan", "Kowal", "1234567890", nullptr, nullptr);
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    Rent rent(1, beginTime, pt::not_a_date_time, client, vehicle);

    // Act
    int cost = rent.getRentCost();

    // Assert
    BOOST_TEST(cost == 0);
}

/**
 * @brief Przypadek do testowania metody getRentCost przy dodatniej liczbie dni wypożyczenia.
 */
BOOST_AUTO_TEST_CASE(TestGetRentCostPositiveDays) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time();
    auto client = std::make_shared<Client>("Jan", "Kowal", "1234567890", nullptr, nullptr);
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    auto rent = std::make_shared<Rent>(2, beginTime, pt::not_a_date_time, client, vehicle);
    rent->endRent(beginTime + pt::hours(48)); // Wynajem na 3 dni

    // Act
    int cost = rent->getRentCost();

    // Assert
    BOOST_TEST(cost == 300);
}

/**
 * @brief Przypadek do testowania metody getRentCost dla klienta typu Default.
 */
BOOST_AUTO_TEST_CASE(TestGetRentCostDefaultClient) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time();
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    auto address = std::make_shared<Address>("Lodz", "Aleje Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    auto client = std::make_shared<Client>("Jan", "Kowal", "2468013579", address, clientType);
    auto rent = std::make_shared<Rent>(1, beginTime, pt::not_a_date_time, client, vehicle);

    // Act
    rent->endRent(beginTime + pt::hours(24)); // Wynajem na 2 dni
    int cost = rent->getRentCost();

    // Assert
    BOOST_TEST(cost == 200);
}

/**
 * @brief Przypadek do testowania metody getRentCost dla klienta typu Bronze.
 */
BOOST_AUTO_TEST_CASE(TestGetRentCostBronzeClient) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time();
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    auto address = std::make_shared<Address>("Lodz", "Aleje Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    auto client = std::make_shared<Client>("Jan", "Kowal", "2468013579", address, clientType);
    client->setClientType(std::make_shared<Bronze>());
    auto rent = std::make_shared<Rent>(2, beginTime, pt::not_a_date_time, client, vehicle);

    // Act
    rent->endRent(beginTime + pt::hours(24)); // Wynajem na 2 dni
    int cost = rent->getRentCost();
    int cost_after_discount = client->applyDiscount(cost);
    // Assert
    BOOST_TEST(cost_after_discount == 197); // 3 zniżki dla klientów
}

/**
 * @brief Przypadek do testowania metody getRentCost dla klienta typu Silver.
 */
BOOST_AUTO_TEST_CASE(TestGetRentCostSilverClient) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time();
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    auto address = std::make_shared<Address>("Lodz", "Aleje Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    auto client = std::make_shared<Client>("Jan", "Kowal", "2468013579", address, clientType);
    client->setClientType(std::make_shared<Silver>());
    auto rent = std::make_shared<Rent>(2, beginTime, pt::not_a_date_time, client, vehicle);

    // Act
    rent->endRent(beginTime + pt::hours(24)); // Wynajem na 2 dni
    int cost = rent->getRentCost();
    int cost_after_discount = client->applyDiscount(cost);
    // Assert
    BOOST_TEST(cost_after_discount == 194); // 6 zniżki dla klientów Silver
}

/**
 * @brief Przypadek do testowania metody getRentCost dla klienta typu Gold.
 */
BOOST_AUTO_TEST_CASE(TestGetRentCostGoldClient) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time();
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    auto address = std::make_shared<Address>("Lodz", "Aleje Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    auto client = std::make_shared<Client>("Jan", "Kowal", "2468013579", address, clientType);
    client->setClientType(std::make_shared<Gold>());
    auto rent = std::make_shared<Rent>(2, beginTime, pt::not_a_date_time, client, vehicle);

    // Act
    rent->endRent(beginTime + pt::hours(24)); // Wynajem na 2 dni
    int cost = rent->getRentCost();
    int cost_after_discount = client->applyDiscount(cost);
    // Assert
    BOOST_TEST(cost_after_discount == 190); // 5% zniżki dla klientów Gold
}

/**
 * @brief Przypadek do testowania metody getRentCost dla klienta typu Premium.
 */
BOOST_AUTO_TEST_CASE(TestGetRentCostPlatinumClient) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time();
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    auto address = std::make_shared<Address>("Lodz", "Aleje Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    auto client = std::make_shared<Client>("Jan", "Kowal", "2468013579", address, clientType);
    client->setClientType(std::make_shared<Platinum>());
    auto rent = std::make_shared<Rent>(2, beginTime, pt::not_a_date_time, client, vehicle);

    // Act
    rent->endRent(beginTime + pt::hours(24)); // Wynajem na 2 dni
    int cost = rent->getRentCost();
    int cost_after_discount = client->applyDiscount(cost);
    // Assert
    BOOST_TEST(cost_after_discount == 180); // 10% zniżki dla klientów Platinum
}

/**
 * @brief Przypadek do testowania metody getRentCost dla klienta typu Diamond.
 */
BOOST_AUTO_TEST_CASE(TestGetRentCostDiamondClient) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time();
    auto vehicle = std::make_shared<Vehicle>("EL 21B15", 100);
    auto address = std::make_shared<Address>("Lodz", "Aleje Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    auto client = std::make_shared<Client>("Jan", "Kowal", "2468013579", address, clientType);
    client->setClientType(std::make_shared<Diamond>());
    auto rent = std::make_shared<Rent>(2, beginTime, pt::not_a_date_time, client, vehicle);

    // Act
    rent->endRent(beginTime + pt::hours(24)); // Wynajem na 2 dni
    int cost = rent->getRentCost();
    int cost_after_discount = client->applyDiscount(cost);
    // Assert
    BOOST_TEST(cost_after_discount == 160); // 20% zniżki dla klientów Diamond przy cenie pomiędzy 125 a 250
}

BOOST_AUTO_TEST_SUITE_END()
