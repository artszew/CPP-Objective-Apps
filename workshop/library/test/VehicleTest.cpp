/**
 * @file VehicleTest.cpp
 * @brief Plik zawierający testy jednostkowe dla klasy Vehicle i podklas Bicycle, Car, Moped.
 */
#include <boost/test/unit_test.hpp>
#include "../../library/include/model/Vehicle.h"
#include "../../library/include/model/Bicycle.h"
#include "../../library/include/model/Car.h"
#include "../../library/include/model/Moped.h"
#include "../../library/include/model/MotorVehicle.h"
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

BOOST_AUTO_TEST_SUITE(TestVehicleRentalPrice)

/**
 * @brief Test sprawdzający poprawność wyliczania ceny wypożyczenia dla roweru.
 */
BOOST_AUTO_TEST_CASE(BicycleRentalPrice)
{
    // Arrange
    auto bicycle = std::make_shared<Bicycle>("EL 21B15", 10);

    // Act
    double actualPrice = bicycle->getActualRentalPrice();

    // Assert
    BOOST_CHECK_CLOSE(actualPrice, 10.0, 0.01);
}

/**
 * @brief Test sprawdzający poprawność wyliczania ceny wypożyczenia dla motoroweru.
 */
BOOST_AUTO_TEST_CASE(MopedRentalPrice)
{
    // Arrange
    auto moped = std::make_shared<Moped>("EL 21B15", 10, 50);

    // Act
    double actualPrice = moped->getActualRentalPrice();

    // Assert
    BOOST_CHECK_CLOSE(actualPrice, 10.0, 0.01);
}

/**
 * @brief Test sprawdzający poprawność wyliczania ceny wypożyczenia dla samochodu segmentu A.
 */
BOOST_AUTO_TEST_CASE(CarRentalPrice_SegmentA)
{
    // Arrange
    auto car = std::make_shared<Car>("EL 21B15", 10, 1500, SegmentType::A);

    // Act
    double actualPrice = car->getActualRentalPrice();

    // Assert
     BOOST_CHECK_CLOSE(actualPrice, 12.5, 0.01); // 10 * 1.25 (dla 1500 cm3) * 1.0 (Segment A)
}

/**
 * @brief Test sprawdzający poprawność wyliczania ceny wypożyczenia dla samochodu segmentu B.
 */
BOOST_AUTO_TEST_CASE(CarRentalPrice_SegmentB)
{
    // Arrange
    auto car = std::make_shared<Car>("EL 21B15", 10, 1500, SegmentType::B);

    // Act
    double actualPrice = car->getActualRentalPrice();

    // Assert
     BOOST_CHECK_CLOSE(actualPrice, (10*1.25*1.1), 0.01); // 10 * 1.25 (dla 1500 cm3) * 1.1 (Segment B)
}

/**
 * @brief Test sprawdzający poprawność wyliczania ceny wypożyczenia dla samochodu segmentu C.
 */
BOOST_AUTO_TEST_CASE(CarRentalPrice_SegmentC)
{
    // Arrange
    auto car = std::make_shared<Car>("EL 21B15", 10, 1500, SegmentType::C);

    // Act
    double actualPrice = car->getActualRentalPrice();

    // Assert
    BOOST_CHECK_CLOSE(actualPrice, 15.0, 0.01); // 10 * 1.25 (dla 1500 cm3) * 1.2 (Segment C)
}

/**
 * @brief Test sprawdzający poprawność wyliczania ceny wypożyczenia dla samochodu segmentu D.
 */
BOOST_AUTO_TEST_CASE(CarRentalPrice_SegmentD)
{
    // Arrange
   auto car = std::make_shared<Car>("EL 21B15", 10, 1500, SegmentType::D);

    // Act
    double actualPrice = car->getActualRentalPrice();

    // Assert
    BOOST_CHECK_CLOSE(actualPrice, 16.25, 0.01); // 10 * 1.25 (dla 1500 cm3) * 1.3 (Segment D)
}

/**
 * @brief Test sprawdzający poprawność wyliczania ceny wypożyczenia dla samochodu segmentu E.
 */
BOOST_AUTO_TEST_CASE(CarRentalPrice_SegmentE)
{
    // Arrange
    auto car = std::make_shared<Car>("EL 21B15", 10, 1500, SegmentType::E);

    // Act
    double actualPrice = car->getActualRentalPrice();

    // Assert
    BOOST_CHECK_CLOSE(actualPrice, 18.75, 0.01); // 10 * 1.25 (dla 1500 cm3) * 1.5 (Segment E)
}

BOOST_AUTO_TEST_SUITE_END()
