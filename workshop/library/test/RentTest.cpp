/**
 * @file RentTest.cpp
 * @brief Plik zawierający testy jednostkowe dla klasy Rent.
 */
#include <boost/test/unit_test.hpp>
#include <boost/date_time.hpp>
#include "../include/model/Rent.h"
#include "../include/model/Vehicle.h"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

BOOST_AUTO_TEST_SUITE(RentTests)

/**
 * @brief Przypadek do testowania metody endRent przy braku czasu zakończenia i czasie rozpoczęcia w przeszłości.
 */
BOOST_AUTO_TEST_CASE(TestEndRentNotSpecified) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time();
    Rent rent(1, beginTime, pt::not_a_date_time, nullptr, nullptr);

    // Act
    rent.endRent(pt::not_a_date_time);

    // Assert
    BOOST_TEST(rent.getRentDays() == 0); // Brak zakończenia
}

/**
 * @brief Przypadek do testowania metody endRent przy braku czasu zakończenia i czasie rozpoczęcia w przeszłości.
 */
BOOST_AUTO_TEST_CASE(TestEndRentNotSpecifiedInPast) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time() - pt::seconds(1);
    Rent rent(1, beginTime, pt::not_a_date_time, nullptr, nullptr);

    // Act
    rent.endRent(pt::not_a_date_time);

    // Assert
    BOOST_TEST(rent.getRentDays() == 0); // Brak zakończenia
}

/**
 * @brief Przypadek do testowania metody endRent przy podanym czasie zakończenia.
 */
BOOST_AUTO_TEST_CASE(TestEndRentSpecified) {
        // Arrange
        pt::ptime beginTime = pt::second_clock::local_time();
        pt::ptime endTime = beginTime + pt::hours(1);
        Rent rent(1, beginTime, pt::not_a_date_time, nullptr, nullptr);

        // Act
        rent.endRent(endTime);

        // Assert
        BOOST_TEST(rent.getRentDays() == 1); // Sprawdzamy, czy dni wypożyczenia są poprawne
}

/**
 * @brief Przypadek do testowania metody endRent przy podanym czasie zakończenia w przeszłości.
 */
BOOST_AUTO_TEST_CASE(TestEndRentSpecifiedInPast) {
        // Arrange
        pt::ptime beginTime = pt::second_clock::local_time();
        pt::ptime endTime = beginTime - pt::hours(1);
        Rent rent(1, beginTime, pt::not_a_date_time, nullptr, nullptr);

        // Act
        rent.endRent(endTime);

        // Assert
        BOOST_TEST(rent.getRentDays() == 0); // Sprawdzamy, czy dni wypożyczenia są poprawne
}

/**
 * @brief Przypadek do testowania metody getRentDays na wartościach granicznych.
 */
BOOST_AUTO_TEST_CASE(TestGetRentDaysBoundaryValues) {
        // Arrange
        pt::ptime beginTime = pt::second_clock::local_time();

        // Act & Assert
        Rent rent1(1, beginTime, beginTime + pt::seconds(59), nullptr, nullptr);
        rent1.endRent(beginTime + pt::seconds(59));
        BOOST_TEST(rent1.getRentDays() == 0);

        Rent rent2(2, beginTime, pt::not_a_date_time, nullptr, nullptr);
        rent2.endRent(beginTime + pt::minutes(1));
        BOOST_TEST(rent2.getRentDays() == 1);

        Rent rent3(3, beginTime, pt::not_a_date_time, nullptr, nullptr);
        rent3.endRent(beginTime + pt::hours(23) + pt::minutes(59));
        BOOST_TEST(rent3.getRentDays() == 1);

        Rent rent4(4, beginTime, pt::not_a_date_time, nullptr, nullptr);
        rent4.endRent(beginTime + pt::hours(24));
        BOOST_TEST(rent4.getRentDays() == 2);

        Rent rent5(5, beginTime, pt::not_a_date_time, nullptr, nullptr);
        rent5.endRent(beginTime + pt::hours(24) + pt::minutes(1));
        BOOST_TEST(rent5.getRentDays() == 2);
}

/**
 * @brief Przypadek do testowania metody getRentDays bez podanego czasu zakończenia.
 */
BOOST_AUTO_TEST_CASE(TestGetRentDaysNoEndTime) {
        // Arrange
        pt::ptime beginTime = pt::second_clock::local_time();
        Rent rent(6, beginTime, pt::not_a_date_time, nullptr, nullptr);

        // Act
        // (no action needed, as endTime is not specified)

        // Assert
        BOOST_TEST(rent.getRentDays() == 0);
}

/**
 * @brief Przypadek do testowania metody getRentCost bez podanego pojazdu.
 */
BOOST_AUTO_TEST_CASE(TestGetRentCost) {
        // Arrange
        Rent rent(7, pt::second_clock::local_time(), pt::not_a_date_time, nullptr, nullptr);

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
        Rent rent(8, pt::second_clock::local_time(), pt::not_a_date_time, nullptr, nullptr);

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
    Vehicle* vehicle = new Vehicle("EL 21B15", 100);
    Rent rent(1, beginTime, pt::not_a_date_time, nullptr, vehicle);

    // Act
    int cost = rent.getRentCost();

    // Assert
    BOOST_TEST(cost == 0);

    delete vehicle;
}

/**
 * @brief Przypadek do testowania metody getRentCost przy dodatniej liczbie dni wypożyczenia.
 */
BOOST_AUTO_TEST_CASE(TestGetRentCostPositiveDays) {
    // Arrange
    pt::ptime beginTime = pt::second_clock::local_time();
    Vehicle* vehicle = new Vehicle("EL 21B15", 100);
    Rent rent(2, beginTime, pt::not_a_date_time, nullptr, vehicle);
    rent.endRent(beginTime + pt::hours(48)); // Wynajem na 3 dni

    // Act
    int cost = rent.getRentCost();

    // Assert
    BOOST_TEST(cost == 300);

    delete vehicle;
}


BOOST_AUTO_TEST_SUITE_END()
