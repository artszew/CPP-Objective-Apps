#include <boost/test/unit_test.hpp>
#include "../../library/include/model/Client.h"

namespace btt = boost::test_tools;


BOOST_AUTO_TEST_SUITE(TestClientSetters)
/**
 * @brief Przypadek do testowania metody set dla imienia.
 */
BOOST_AUTO_TEST_CASE(SetFirstName_NewValue)
{
    // Arrange
    Client client("Jan", "Kowal", "2468013579");

    // Act
    client.setFirstName("Janusz");

    // Assert
    BOOST_TEST(client.getFirstName() == "Janusz");
}

/**
 * @brief Przypadek do testowania warunku if metody set dla imienia.
 */
BOOST_AUTO_TEST_CASE(SetFirstName_EmptyString)
{
    // Arrange
    Client client("Jan", "Kowal", "2468013579");
    const std::string previousFirstName = client.getFirstName();

    // Act
    client.setFirstName("");

    // Assert
    BOOST_TEST(client.getFirstName() == previousFirstName);
}

/**
 * @brief Przypadek do testowania metody set dla nazwiska.
 */
BOOST_AUTO_TEST_CASE(SetLastName_NewValue)
{
    // Arrange
    Client client("Jan", "Kowal", "2468013579");

    // Act
    client.setLastName("Nowak");

    // Assert
    BOOST_TEST(client.getLastName() == "Nowak");
}

/**
 *  * @brief Przypadek do testowania warunku if metody set dla nazwiska.
 */
BOOST_AUTO_TEST_CASE(SetLastName_EmptyString)
{
    // Arrange
    Client client("Jan", "Kowal", "2468013579");
    const std::string previousLastName = client.getLastName();

    // Act
    client.setLastName("");

    // Assert
    BOOST_TEST(client.getLastName() == previousLastName);
}

BOOST_AUTO_TEST_SUITE_END()

