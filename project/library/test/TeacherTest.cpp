/**
 * @file TeacherTest.cpp
 * @brief Plik zawierający testy jednostkowe dla klasy Teacher.
 */
#include <boost/test/unit_test.hpp>
#include "../../library/include/model/Lesson.h"
#include "../../library/include/model/Teacher.h"
#include "../../library/include/typedefs.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <memory>
#include <vector>
namespace pt = boost::posix_time;
namespace btt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(TestTeacherConstructorAndSetters)

/**
 * @brief Przypadek do testowania konstruktora parametrowego klasy Teacher.
 */
BOOST_AUTO_TEST_CASE(TeacherConstructorTest)
{
    // Arrange
    Teacher teacher("Artur", 60, 1);
    // Assert
    BOOST_TEST("Artur" == teacher.getFirstName());
    BOOST_TEST(60 == teacher.getBasePrice());
    BOOST_TEST(1 == teacher.getTeacherID());
}
/**
 * @brief Przypadek do testowania metody set dla numeru rejestracyjnego.
 */
BOOST_AUTO_TEST_CASE(SetFirstName_NewValue)
{
    // Arrange
    Teacher teacher("Artur", 60, 1);

    // Act
    teacher.setFirstName("Janusz");

    // Assert
    BOOST_TEST(teacher.getFirstName() == "Janusz");
}

/**
 * @brief Przypadek do testowania warunku if metody set dla numeru rejestracyjnego.
 */
BOOST_AUTO_TEST_CASE(SetFirstName_EmptyString)
{
// Arrange
    Teacher teacher("Artur", 60, 1);
    const std::string previousFirstName = teacher.getFirstName();

    // Act
    teacher.setFirstName("");

    // Assert
    BOOST_TEST(teacher.getFirstName() == previousFirstName);
}

/**
 * @brief Przypadek do testowania metody set dla ceny wypozyczenia pojazdu za 1 dobe.
 */
BOOST_AUTO_TEST_CASE(SetBasePrice_GoodValue)
{
    // Arrange
    Teacher teacher("Artur", 60, 1);

    // Act
    int newBasePrice = 80;
    teacher.setBasePrice(newBasePrice);

    // Assert
    BOOST_TEST(teacher.getBasePrice() == 80);
}

BOOST_AUTO_TEST_CASE(SetBasePrice_BadValue)
{
    // Arrange
    Teacher teacher("Artur", 60, 1);

    // Act
    int newBasePrice = -60;
    teacher.setBasePrice(newBasePrice);

    // Assert
    BOOST_TEST(teacher.getBasePrice() == 60);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestTeacherPlannedLessonsVector)

/**
 * @brief Przypadek do testowania metody dodającej wypożyczenie do klienta.
 */
BOOST_AUTO_TEST_CASE(AddLessonTest) {
        // Arrange
        Teacher teacher("Artur", 60, 1);
        TeacherPtr teacherPtr = std::make_shared<Teacher>(teacher);
        std::string lessonDate("2024-06-26 14:20:00.000");
        pt::ptime t=pt::time_from_string(lessonDate);
        LessonPtr lesson = std::make_shared<Lesson>(1, t, 1, "Math", nullptr, teacherPtr);

        // Act
        teacher.addLesson(lesson);

        // Assert
        BOOST_TEST(teacher.getPlannedLessons().size() == 1);
        BOOST_TEST(teacher.getPlannedLessons()[0] == lesson);
}

BOOST_AUTO_TEST_SUITE_END()
