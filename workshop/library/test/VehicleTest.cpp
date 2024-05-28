#include <boost/test/unit_test.hpp>
#include "../../library/include/model/Vehicle.h"

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(TestVehicleSetters)
/**
 * @brief Przypadek do testowania metody set dla numeru rejestracyjnego.
 */
BOOST_AUTO_TEST_CASE(SetPlateNumber_NewValue)
{
    // Arrange
    Vehicle vehicle_1("EL 21B15", 10);

    // Act
    vehicle_1.setPlateNumber("CB 21B15");

    // Assert
    BOOST_TEST(vehicle_1.getPlateNumber() == "CB 21B15");
}

/**
 * @brief Przypadek do testowania warunku if metody set dla numeru rejestracyjnego.
 */
BOOST_AUTO_TEST_CASE(SetPlateNumber_EmptyString)
{
    // Arrange
    Vehicle vehicle_1("EL 21B15", 10);
    const std::string previousPlateNumber = vehicle_1.getPlateNumber();

    // Act
    vehicle_1.setPlateNumber("");

    // Assert
    BOOST_TEST(vehicle_1.getPlateNumber() == previousPlateNumber);
}

/**
 * @brief Przypadek do testowania metody set dla ceny wypozyczenia pojazdu za 1 dobe.
 */
BOOST_AUTO_TEST_CASE(SetBasePrice_GoodValue)
{
    // Arrange
    Vehicle vehicle_1("EL 21B15", 10);

    // Act
    unsigned int newBasePrice = 295;
    vehicle_1.setBasePrice(newBasePrice);

    // Assert
    BOOST_TEST(vehicle_1.getBasePrice() ==295);
}

/**
 * @brief Przypadek do testowania ustawienia wartości logicznej rented.
 */
BOOST_AUTO_TEST_CASE(SetRented_NewValue)
{
    // Arrange
    Vehicle vehicle_1("EL 21B15", 10);

    // Act
    vehicle_1.setRented(true);

    // Assert
    BOOST_TEST(vehicle_1.isRented() == true);
}
BOOST_AUTO_TEST_SUITE_END()
