/**
 * @file ClientType.cpp
 * @brief Plik zawierający implementacje metod klasy ClientType, która reprezentuje typ Klienta.
 */
 
 /**
 * @brief Headery klas, których metody są wykorzystywane w klasie ClientType
 * @path_to ClientType.h 
 * @path_to Client.h
 */
#include "../../library/include/model/ClientType.h"
#include "../../library/include/model/Client.h"

/**
 * @brief Oblicza zniżkę dla klienta typu "PrimarySchool".
 * @param price Cena, dla której obliczana jest zniżka.
 * @return Cena po zastosowaniu zniżki 25% dla uczniów szkoły podstawowej.
 */
float PrimarySchool::applyDiscount(float price) const {
    return price * 0.75;
}

/**
 * @brief Pobiera informacje o typie klienta.
 * @return Informacja o typie klienta.
 */
std::string PrimarySchool::getInfo() const {
    return "Primary School";
}

/**
 * @brief Oblicza zniżkę dla klienta typu "SecondarySchool".
 * @param price Cena, dla której obliczana jest zniżka.
 * @return Cena po zastosowaniu zniżki (w tym przypadku nie ma żadnych rabatów ani podwyżek).
 */
float SecondarySchool::applyDiscount(float price) const {
        return price; 
}

/**
 * @brief Pobiera informacje o typie klienta.
 * @return Informacje o typie klienta.
 */
std::string SecondarySchool::getInfo() const {
    return "Secondary School";
}

/**
 * @brief Oblicza podwyżkę dla klienta typu "Student".
 * @param price Cena, dla której obliczana jest podwyżka.
 * @return Cena po zastosowaniu podwyżki.
 */
float Student::applyDiscount(float price) const {
    return price * 1.5;
}

/**
 * @brief Pobiera informacje o typie klienta.
 * @return Informacje o typie klienta.
 */
std::string Student::getInfo() const {
    return "Student";
}
