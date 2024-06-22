/**
 * @file ClientType.cpp
 * @brief Plik zawierający definicje metod klasy ClientType, która reprezentuje typ Klienta.
 */
#include "../../library/include/model/ClientType.h"

// PrimarySchool

/**
 * @brief Oblicza zniżkę dla klienta typu "PrimarySchool".
 * @param price Cena, dla której obliczana jest zniżka.
 * @param schoolClass Klasa klienta.
 * @return Cena po zastosowaniu zniżki.
 */
float PrimarySchool::applyDiscount(float price) const {
    return price * 0.75; // Rabat 25% dla uczniów szkoły podstawowej
}

/**
 * @brief Pobiera informacje o typie klienta.
 * @return Informacje o typie klienta.
 */
std::string PrimarySchool::getInfo() const {
    return "Primary School";
}

// SecondarySchool

/**
 * @brief Oblicza zniżkę dla klienta typu "SecondarySchool".
 * @param price Cena, dla której obliczana jest zniżka.
 * @return Cena po zastosowaniu zniżki.
 */
float SecondarySchool::applyDiscount(float price) const {
    if (isExtensionLevel()) {
        return price * 1.25; // poziom rozszerzony droższy
    } else {
        return price;
    }
}

/**
 * @brief Pobiera informacje o typie klienta.
 * @return Informacje o typie klienta.
 */
std::string SecondarySchool::getInfo() const {
    return "Secondary School";
}

/**
 * @brief Sprawdza, czy klient jest na poziomie rozszerzonym.
 * @return true, jeśli klient jest na poziomie rozszerzonym, w przeciwnym razie false.
 */
bool SecondarySchool::isExtensionLevel() const {
    return extensionLevel;
}

// Student

/**
 * @brief Oblicza zniżkę dla klienta typu "Student".
 * @param price Cena, dla której obliczana jest zniżka.
 * @return Cena po zastosowaniu zniżki.
 */
float Student::applyDiscount(float price) const {
    return price * 1.5; // nauka wyższa najdroższa
}

/**
 * @brief Pobiera informacje o typie klienta.
 * @return Informacje o typie klienta.
 */
std::string Student::getInfo() const {
    return "Student";
}

