/**
 * @file AddressTest.cpp
 * @brief Plik zawierający testy jednostkowe dla klasy Address.
 */
#include <boost/test/unit_test.hpp>
#include "../../library/include/model/Address.h"

namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(TestAddressSetters)
/**
 * @brief Przypadek do testowania metody set dla adresu.
 */
BOOST_AUTO_TEST_CASE(SetCity_NewValue)
{
    // Arrange
    Address address("Lodz", "Aleja Politechniki", "20/4");

    // Act
    address.setCity("Bydgoszcz");

    // Assert
    BOOST_TEST(address.getCity() == "Bydgoszcz");
}

/**
 * @brief Przypadek do testowania warunku if metody set dla miasta.
 */
BOOST_AUTO_TEST_CASE(SetCity_EmptyString)
{
    // Arrange
    Address address("Lodz", "Aleja Politechniki", "20/4");
    const std::string previousCity = address.getCity();

    // Act
    address.setCity("");

    // Assert
    BOOST_TEST(address.getCity() == previousCity);
}

/**
 * @brief Przypadek do testowania metody set dla ulicy.
 */
BOOST_AUTO_TEST_CASE(SetStreet_NewValue)
{
    // Arrange
    Address address("Lodz", "Aleja Politechniki", "20/4");

    // Act
    address.setStreet("Wolczanska");

    // Assert
    BOOST_TEST(address.getStreet() == "Wolczanska");
}

/**
 *  * @brief Przypadek do testowania warunku if metody set dla ulicy.
 */
BOOST_AUTO_TEST_CASE(SetStreet_EmptyString)
{
    // Arrange
    Address address("Lodz", "Aleja Politechniki", "20/4");
    const std::string previousStreet = address.getStreet();

    // Act
    address.setStreet("");

    // Assert
    BOOST_TEST(address.getStreet() == previousStreet);
}

/**
 * @brief Przypadek do testowania metody set dla numeru domu.
 */
BOOST_AUTO_TEST_CASE(SetNumber_NewValue)
{
    // Arrange
    Address address("Lodz", "Aleja Politechniki", "20/4");

    // Act
    address.setNumber("4/20");

    // Assert
    BOOST_TEST(address.getNumber() == "4/20");
}

/**
 *  * @brief Przypadek do testowania warunku if metody set dla numeru domu.
 */
BOOST_AUTO_TEST_CASE(SetNumber_EmptyString)
{
    // Arrange
    Address address("Lodz", "Aleja Politechniki", "20/4");
    const std::string previousNumber = address.getNumber();

    // Act
    address.setNumber("");

    // Assert
    BOOST_TEST(address.getNumber() == previousNumber);
}
BOOST_AUTO_TEST_SUITE_END()
