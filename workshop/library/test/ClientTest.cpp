#include <boost/test/unit_test.hpp>
#include "../../library/include/model/Client.h"

namespace btt = boost::test_tools;

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jan";
    const std::string testLastName = "Kowal";
    const std::string testPersonalID = "2468013579";
    Address *testaddress1;
    Address *testaddress2;

    TestSuiteClientFixture() {
        testaddress1 = new Address("Lodz", "Aleje Politechniki", "20/4");
        testaddress2 = new Address("Lodz", "Wolczanska", "8");
    }

    ~TestSuiteClientFixture() {
        delete testaddress1;
        delete testaddress2;
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

BOOST_AUTO_TEST_CASE(ParameterConstructorTest) {
    // Arrange
    Client c(testFirstName, testLastName, testPersonalID, testaddress1);

    // Assert
    BOOST_TEST(testFirstName == c.getFirstName());
    BOOST_TEST(testLastName == c.getLastName());
    BOOST_TEST(testPersonalID == c.getPersonalID());
    BOOST_TEST(testaddress1 == c.getAddress());
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestClientSetters)
/**
 * @brief Przypadek do testowania metody set dla imienia.
 */
BOOST_AUTO_TEST_CASE(SetFirstName_NewValue)
{
    // Arrange
    Address address("Lodz", "Aleja Politechniki", "20/4");
    Client client("Jan", "Kowal", "2468013579", &address);

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
    Address address("Lodz", "Aleja Politechniki", "20/4");
    Client client("Jan", "Kowal", "2468013579", &address);
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
    Address address("Lodz", "Aleja Politechniki", "20/4");
    Client client("Jan", "Kowal", "2468013579", &address);

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
    Address address("Lodz", "Aleja Politechniki", "20/4");
    Client client("Jan", "Kowal", "2468013579" , &address);
    const std::string previousLastName = client.getLastName();

    // Act
    client.setLastName("");

    // Assert
    BOOST_TEST(client.getLastName() == previousLastName);
}


/**
 * @brief Przypadek do testowania metody setAddress.
 */
BOOST_AUTO_TEST_CASE(SetAddress_ValidAddress)
{
    // Arrange
    Address address("Lodz", "Aleja Politechniki", "20/4");
    Client client("Jan", "Kowal", "2468013579", &address);

    // Act
    client.setAddress(&address);

    // Assert
    BOOST_TEST(client.getAddress() == &address);
}

/**
 * @brief Przypadek do testowania warunku if metody setAddress dla pustego wskaźnika.
 */
BOOST_AUTO_TEST_CASE(SetAddress_Nullptr)
{
    // Arrange
    Address address("Lodz", "Aleja Politechniki", "20/4");
    Client client("Jan", "Kowal", "2468013579" , &address);
    Address* previousAddress = client.getAddress();

    // Act
    client.setAddress(nullptr);

    // Assert
    BOOST_TEST(client.getAddress() == previousAddress);
}

/**
 * @brief Przypadek do testowania poprawności zwracanych informacji przez getInfo z ustawionym adresem.
 */
BOOST_AUTO_TEST_CASE(GetInfo_WithAddress)
{
    // Arrange
    Address address("Lodz", "Aleja Politechniki", "20/4");
    Client client("Jan", "Kowal", "2468013579", &address);

    // Act
    std::string info = client.getInfo();

    // Assert
    BOOST_TEST(info.find("Address:\n City: Lodz, street: Aleja Politechniki, number: 20/4") != std::string::npos);
}
BOOST_AUTO_TEST_SUITE_END()
