/**
 * @file ClientTest.cpp
 * @brief Plik zawierający testy jednostkowe dla klasy Client.
 */
#include <boost/test/unit_test.hpp>
#include "../../library/include/model/Client.h"
#include "../../library/include/model/ClientType.h"
#include "../../library/include/model/Address.h"
#include "../../library/include/model/Rent.h"
#include <memory>
#include <vector>

namespace btt = boost::test_tools;

/**
 * @brief Przykładowa struktura danych dla klasy Client.
 */
struct TestSuiteClientFixture {
    const std::string testFirstName = "Jan";
    const std::string testLastName = "Kowal";
    const std::string testPersonalID = "2468013579";
    std::shared_ptr<Address> testaddress1;
    std::shared_ptr<Address> testaddress2;

    TestSuiteClientFixture() {
        testaddress1 = std::make_shared<Address>("Lodz", "Aleje Politechniki", "20/4");
        testaddress2 = std::make_shared<Address>("Lodz", "Wolczanska", "8");
    }

    ~TestSuiteClientFixture() {
        // Wskaźniki współdzielone są automatycznie zwalniane
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

/**
 * @brief Przypadek do testowania konstruktora parametrowego klasy Client.
 */
BOOST_AUTO_TEST_CASE(ParameterConstructorTest) {
    // Arrange
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    Client client("Jan", "Kowal", "2468013579", address, clientType);

    // Assert
    BOOST_TEST("Jan" == client.getFirstName());
    BOOST_TEST("Kowal" == client.getLastName());
    BOOST_TEST("2468013579" == client.getPersonalID());
    BOOST_TEST(address == client.getAddress());
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestClientSetters)

/**
 * @brief Przypadek do testowania metody set dla imienia.
 */
BOOST_AUTO_TEST_CASE(SetFirstName_NewValue)
{
    // Arrange
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    Client client("Jan", "Kowal", "2468013579", address, clientType);

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
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    Client client("Jan", "Kowal", "2468013579", address, clientType);
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
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    Client client("Jan", "Kowal", "2468013579", address, clientType);

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
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    Client client("Jan", "Kowal", "2468013579", address, clientType);
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
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto address2 = std::make_shared<Address>("Gniezno", "Promenada McDonalda", "4/20");
    auto clientType = std::make_shared<Default>();
    Client client("Jan", "Kowal", "2468013579", address, clientType);

    // Act
    client.setAddress(address2);

    // Assert
    BOOST_TEST(client.getAddress() == address2);
}

/**
 * @brief Przypadek do testowania warunku if metody setAddress dla pustego wskaźnika.
 */
BOOST_AUTO_TEST_CASE(SetAddress_Nullptr)
{
    // Arrange
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    Client client("Jan", "Kowal", "2468013579", address, clientType);
    std::shared_ptr<Address> previousAddress = client.getAddress();

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
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    Client client("Jan", "Kowal", "2468013579", address, clientType);

    // Act

    // Assert
    BOOST_TEST(client.getAddress() == address);
}

/**
 * @brief Przypadek do testowania metody dodającej wypożyczenie do klienta.
 */
BOOST_AUTO_TEST_CASE(AddRentTest) {
        // Arrange
        auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
        auto clientType = std::make_shared<Default>();
        auto client = std::make_shared<Client>("Jan", "Kowal", "2468013579", address, clientType);
        auto rent = std::make_shared<Rent>(1, pt::second_clock::local_time(), pt::not_a_date_time, client, nullptr);

        // Act
        client->addRent(rent);

        // Assert
        BOOST_TEST(client->getCurrentRents().size() == 1);
        BOOST_TEST(client->getCurrentRents()[0] == rent);
}

/** 
* Test dla klienta typu "Default"
*/
/**
 * @brief Testy dla różnych typów klientów.
 */
BOOST_AUTO_TEST_CASE(DefaultClientTypeTest) {
    // Arrange
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Default>();
    Client client("Jan", "Kowal", "2468013579", address, clientType);

    // Assert
    BOOST_TEST(client.getMaxVehicles() == 1);
    BOOST_TEST(client.applyDiscount(100) == 100);
}

BOOST_AUTO_TEST_CASE(BronzeClientTypeTest) {
    // Arrange
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Bronze>();
    Client client("Jan", "Kowal", "2468013579", address, clientType);

    // Assert
    BOOST_TEST(client.getMaxVehicles() == 2);
    BOOST_TEST(client.applyDiscount(100) == 97);
}

BOOST_AUTO_TEST_CASE(SilverClientTypeTest) {
    // Arrange
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Silver>();
    Client client("Jan", "Kowal", "2468013579", address, clientType);

    // Assert
    BOOST_TEST(client.getMaxVehicles() == 3);
    BOOST_TEST(client.applyDiscount(100) == 94);
}

BOOST_AUTO_TEST_CASE(GoldClientTypeTest) {
    // Arrange
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Gold>();
    Client client("Jan", "Kowal", "2468013579", address, clientType);

    // Assert
    BOOST_TEST(client.getMaxVehicles() == 4);
    BOOST_TEST(client.applyDiscount(100) == 95);
}

BOOST_AUTO_TEST_CASE(PlatinumClientTypeTest) {
    // Arrange
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Platinum>();
    Client client("Jan", "Kowal", "2468013579", address, clientType);

    // Assert
    BOOST_TEST(client.getMaxVehicles() == 5);
    BOOST_TEST(client.applyDiscount(100) == 90);
}

BOOST_AUTO_TEST_CASE(DiamondClientTypeTest) {
    // Arrange
    auto address = std::make_shared<Address>("Lodz", "Aleja Politechniki", "20/4");
    auto clientType = std::make_shared<Diamond>();
    Client client("Jan", "Kowal", "2468013579", address, clientType);

    // Assert
    BOOST_TEST(client.getMaxVehicles() == 10);
    BOOST_TEST(client.applyDiscount(100) == 90);
    BOOST_TEST(client.applyDiscount(200) == 160);
    BOOST_TEST(client.applyDiscount(300) == 210);
    BOOST_TEST(client.applyDiscount(600) == 360);
}

BOOST_AUTO_TEST_SUITE_END()

