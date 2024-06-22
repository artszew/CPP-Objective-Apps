/**
 * @file ClientTest.cpp
 * @brief Plik zawierający testy jednostkowe dla klasy Client.
 */
#include <boost/test/unit_test.hpp>
#include "../../library/include/model/Client.h"
#include "../../library/include/model/ClientType.h"
#include "../../library/include/model/Lesson.h"
#include "../../library/include/typedefs.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <memory>
#include <vector>
namespace pt = boost::posix_time;
namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(TestClientConstructor)

/**
 * @brief Przypadek do testowania konstruktora parametrowego klasy Client.
 */
BOOST_AUTO_TEST_CASE(ParameterConstructorTest) {
    // Arrange
    Client client("Jan", 1, 6, std::make_shared<PrimarySchool>());

    // Assert
    BOOST_TEST("Jan" == client.getFirstName());
    BOOST_TEST(1 == client.getClientID());
    BOOST_TEST(6 == client.getSchoolClass());
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestClientSetters)
/**
 * @brief Przypadek do testowania metody set dla imienia.
 */
BOOST_AUTO_TEST_CASE(SetFirstName_NewValue)
{
    // Arrange
    Client client("Jan", 1, 6, std::make_shared<PrimarySchool>());

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
    Client client("Jan", 1, 6, std::make_shared<PrimarySchool>());
    const std::string previousFirstName = client.getFirstName();

    // Act
    client.setFirstName("");

    // Assert
    BOOST_TEST(client.getFirstName() == previousFirstName);
}

/**
 * @brief Przypadek do testowania metody set dla nazwiska.
 */
BOOST_AUTO_TEST_CASE(SetSchoolClass_NewValue)
{
    // Arrange
    Client client("Jan", 1, 6, std::make_shared<PrimarySchool>());

    // Act
    client.setSchoolClass(8);

    // Assert
    BOOST_TEST(client.getSchoolClass() == 8);
}


/**
 * @brief Przypadek do testowania poprawności zwracanych informacji przez getInfo.
 */
BOOST_AUTO_TEST_CASE(GetInfo)
{
    // Arrange
    Client client("Jan", 1, 6, std::make_shared<PrimarySchool>());

    // Assert
    BOOST_TEST(client.getInfo()=="Client: First name: Jan, client ID: 1, school class: 6Client type: Primary School");
}

/**
 * @brief Przypadek do testowania metody dodającej wypożyczenie do klienta.
 */
BOOST_AUTO_TEST_CASE(AddLessonTest) {
        // Arrange
        Client client("Jan", 1, 6, std::make_shared<PrimarySchool>());
        ClientPtr clientPtr = std::make_shared<Client>(client);
        std::string lessonDate("2024-06-26 14:20:00.000");
        pt::ptime t=pt::time_from_string(lessonDate);
        LessonPtr lesson = std::make_shared<Lesson>(1, t, 1, "Math", clientPtr, nullptr);

        // Act
        client.addLesson(lesson);

        // Assert
        BOOST_TEST(client.getPlannedLessons().size() == 1);
        BOOST_TEST(client.getPlannedLessons()[0] == lesson);
}


/**
 * @brief Testy dla różnych typów klientów.
 */
 
/** 
* Test dla klienta typu "Primary School"
*/
BOOST_AUTO_TEST_CASE(PrimarySchoolClientTypeTest) {
    // Arrange
    Client client("Jan", 1, 6, std::make_shared<PrimarySchool>());

    // Assert
    BOOST_TEST(client.getClientType() == "Primary School");
}

/** 
* Test dla klienta typu "Secondary School"
*/
BOOST_AUTO_TEST_CASE(SecondarySchoolTypeTest) {
    // Arrange
    Client client("Jan", 1, 6, std::make_shared<SecondarySchool>());

    // Assert
    BOOST_TEST(client.getClientType() == "Secondary School");
}

/** 
* Test dla klienta typu "Student"
*/
BOOST_AUTO_TEST_CASE(StudentTypeTest) {
    // Arrange
    Client client("Jan", 1, 6, std::make_shared<Student>());

    // Assert
    BOOST_TEST(client.getClientType() == "Student");
}

BOOST_AUTO_TEST_SUITE_END()

