/**
 * @file LessonTest.cpp
 * @brief Plik zawierający testy jednostkowe dla klasy Lesson.
 */
#include <boost/test/unit_test.hpp>
#include <memory>
#include "../../library/include/typedefs.h"
#include "../../library/include/RepositoriesManager.h"
#include "../../library/include/model/Lesson.h"
#include "../../library/include/model/Teacher.h"
#include "../../library/include/model/Client.h"
#include "../../library/include/model/ClientType.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <vector>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;


BOOST_AUTO_TEST_SUITE(LessonSettersGettersAndConstructorTests)

/**
 * @brief Przypadek do testowania konstruktorów klasy Lesson
 */
BOOST_AUTO_TEST_CASE(TestLessonConstructor) {
    // Arrange
    std::string lessonDate("2024-06-26 14:20:00.000");
    pt::ptime t=pt::time_from_string(lessonDate);
    LessonPtr lesson = std::make_shared<Lesson>(1, t, 1, "Math", nullptr, nullptr);

    // Assert
    BOOST_TEST(1 == lesson->getLessonID());
    BOOST_TEST(t == lesson->getBeginDateAndTime());
    BOOST_TEST(1 == lesson->getDuration());
    BOOST_TEST("Math" == lesson->getSubject());
}


/**
 * @brief Przypadek do testowania metody set dla beginDateAndTime.
 */
BOOST_AUTO_TEST_CASE(TestSetBeginDateAndTime_GoodValue) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time()+ pt::hours(2);
    LessonPtr lesson = std::make_shared<Lesson>(1, beginTime, 1, "Math", nullptr, nullptr);
    pt::ptime newBeginTime = beginTime+ pt::hours(3);

    // Act
    lesson->setBeginDateAndTime(newBeginTime);
    // Assert
    BOOST_TEST(lesson->getBeginDateAndTime() == newBeginTime);
}

/**
 * @brief Przypadek do testowania metody set dla beginDateAndTime.
 */
BOOST_AUTO_TEST_CASE(TestSetBeginDateAndTime_BadValue) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time()+ pt::hours(2);
    LessonPtr lesson = std::make_shared<Lesson>(1, beginTime, 1, "Math", nullptr, nullptr);
    pt::ptime newBeginTime = beginTime- pt::hours(2);

    // Act
    lesson->setBeginDateAndTime(newBeginTime);
    // Assert
    BOOST_TEST(lesson->getBeginDateAndTime() == beginTime);
}

/**
 * @brief Przypadek do testowania metody set dla trwania zajec.
 */
BOOST_AUTO_TEST_CASE(SetDuration_NewValue)
{
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time()+ pt::hours(2);
    LessonPtr lesson = std::make_shared<Lesson>(1, beginTime, 1, "Math", nullptr, nullptr);

    // Act
    lesson->setDuration(2);

    // Assert
    BOOST_TEST(lesson->getDuration() == 2);
}

/**
 * @brief Przypadek do testowania warunku if metody set dla trwania zajec.
 */
BOOST_AUTO_TEST_CASE(SetDuration_NewBadValue)
{
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time()+ pt::hours(2);
    LessonPtr lesson = std::make_shared<Lesson>(1, beginTime, 1, "Math", nullptr, nullptr);

    // Act
    lesson->setDuration(0.3);

    // Assert
    BOOST_TEST(lesson->getDuration() == 1);
}

/**
 * @brief Przypadek do testowania metody set dla imienia.
 */
BOOST_AUTO_TEST_CASE(SetSubject_NewValue)
{
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time()+ pt::hours(2);
    LessonPtr lesson = std::make_shared<Lesson>(1, beginTime, 1, "Math", nullptr, nullptr);

    // Act
    lesson->setSubject("Physic");

    // Assert
    BOOST_TEST(lesson->getSubject() == "Physic");
}

/**
 * @brief Przypadek do testowania warunku if metody set dla imienia.
 */
BOOST_AUTO_TEST_CASE(SetSubject_EmptyString)
{
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time()+ pt::hours(2);
    LessonPtr lesson = std::make_shared<Lesson>(1, beginTime, 1, "Math", nullptr, nullptr);
    const std::string previousSubject = lesson->getSubject();

    // Act
    lesson->setSubject("");

    // Assert
    BOOST_TEST(lesson->getSubject() == previousSubject);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(LessonsTypesTests)

/**
 * @brief Przypadek do testowania lekcji indywidualnych dla klienta ze szkoły podstawowej.
 */
BOOST_AUTO_TEST_CASE(TestPrimarySchoolIndividualLessons) {
    // Arrange
    auto client1 = std::make_shared<Client>("Jan", 1, 6, std::make_shared<PrimarySchool>()); //szkola podstawowa
    auto teacher = std::make_shared<Teacher>("Artur", 80, 1);
    pt::ptime beginTime = pt::second_clock::local_time()+ pt::hours(2);
    auto individual1 = std::make_shared<Individual>(1, beginTime, 1, "Math", client1, teacher, false, false); // normalna lekcja klienta 1
    auto individual2 = std::make_shared<Individual>(2, beginTime, 1, "Math", client1, teacher, true, false); // pierwsza lekcja klienta1
    auto individual3 = std::make_shared<Individual>(3, beginTime, 1, "Math", client1, teacher, true, true); // pierwsza lekcja stacjonarna klienta1
    auto individual4 = std::make_shared<Individual>(4, beginTime, 1, "Math", client1, teacher, false, true); // normalna lekcja stacjonarna klienta1
    
    // Act
    float price1 = individual1->getLessonPrice();
    float price2 = individual2->getLessonPrice();
    float price3 = individual3->getLessonPrice();
    float price4 = individual4->getLessonPrice();

    // Assert
    BOOST_TEST(price1 == 60);
    BOOST_TEST(price2 == 30);
    BOOST_TEST(price3 == 33);
    BOOST_TEST(price4 == 66);
}



/**
 * @brief Przypadek do testowania lekcji grupowych dla klienta ze szkoły podstawowej.
 */
BOOST_AUTO_TEST_CASE(TestPrimarySchoolGroupCourseLesson) {
    // Arrange
    auto client1 = std::make_shared<Client>("Jan", 1, 6, std::make_shared<PrimarySchool>()); //klasa 4-6
    auto teacher = std::make_shared<Teacher>("Artur", 80, 1);
    pt::ptime beginTime = pt::second_clock::local_time()+ pt::hours(2);
    auto groupCourse1 = std::make_shared<GroupCourse>(1, beginTime, 1, "Math", client1, teacher, AmountOfMembers::Two); // lekcja w grupie 2-osobowej klienta1
    auto groupCourse2 = std::make_shared<GroupCourse>(2, beginTime, 1, "Math", client1, teacher, AmountOfMembers::Three); // lekcja w grupie 3-osobowej klienta1
    auto groupCourse3 = std::make_shared<GroupCourse>(3, beginTime, 1, "Math", client1, teacher, AmountOfMembers::Four); // lekcja w grupie 4-osobowej klienta1

    // Act
    float price1 = groupCourse1->getLessonPrice();
    float price2 = groupCourse2->getLessonPrice();
    float price3 = groupCourse3->getLessonPrice();
    
    // Assert
    BOOST_TEST(price1 == 48);
    BOOST_TEST(price2 == 42);
    BOOST_TEST(price3 == 36);
}

/**
 * @brief Przypadek do testowania lekcji grupowych dla klienta ze szkoły sredniej
 */
BOOST_AUTO_TEST_CASE(TestSecondarySchoolGroupCourseLesson) {
    // Arrange
    auto client1 = std::make_shared<Client>("Jan", 1, 3, std::make_shared<SecondarySchool>()); // uczen szkoly sredniej bez rozszerzenia 
    auto client2 = std::make_shared<Client>("Jan", 2, 3, std::make_shared<SecondarySchool>(), true);
    auto teacher = std::make_shared<Teacher>("Artur", 80, 1);
    pt::ptime beginTime = pt::second_clock::local_time()+ pt::hours(2);
    auto groupCourse1 = std::make_shared<GroupCourse>(1, beginTime, 1, "Math", client1, teacher, AmountOfMembers::Two); // lekcja w grupie 2-osobowej klienta1
    auto groupCourse2 = std::make_shared<GroupCourse>(2, beginTime, 1, "Math", client2, teacher, AmountOfMembers::Two); // lekcja w grupie 2-osobowej klienta2
    
    // Act
    float price1 = groupCourse1->getLessonPrice();
    float price2 = groupCourse2->getLessonPrice();
    
    // Assert
    BOOST_TEST(price1 == 64);
    BOOST_TEST(price2 == 80);
}

BOOST_AUTO_TEST_SUITE_END()
