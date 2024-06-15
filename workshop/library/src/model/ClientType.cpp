/**
 * @file ClientType.cpp
 * @brief Plik zawierający definicje metod klasy ClientType, która reprezentuje typ Klienta.
 */
#include "../../library/include/model/ClientType.h"

// Default
/**
 * @brief Zwraca maksymalną liczbę pojazdów, jakie klient typu "Default" może wypożyczyć jednocześnie.
 * @return Maksymalna liczba pojazdów.
 */
int Default::getMaxVehicles() const {
    return 1;
}

/**
 * @brief Oblicza zniżkę dla klienta typu "Default".
 * @param price Cena, dla której obliczana jest zniżka.
 * @return Cena po zastosowaniu zniżki.
 */
double Default::applyDiscount(double price) const {
    return price;
}

/**
 * @brief Pobiera informacje o typie klienta.
 * @return Informacje o typie klienta.
 */
std::string Default::getInfo() const {
    return "Default";
}

// Bronze
/**
 * @brief Zwraca maksymalną liczbę pojazdów, jakie klient typu "Bronze" może wypożyczyć jednocześnie.
 * @return Maksymalna liczba pojazdów.
 */
int Bronze::getMaxVehicles() const {
    return 2;
}

/**
 * @brief Oblicza zniżkę dla klienta typu "Bronze".
 * @param price Cena, dla której obliczana jest zniżka.
 * @return Cena po zastosowaniu zniżki.
 */
double Bronze::applyDiscount(double price) const {
    return price - 3;
}

/**
 * @brief Pobiera informacje o typie klienta.
 * @return Informacje o typie klienta.
 */
std::string Bronze::getInfo() const {
    return "Bronze";
}

// Silver
/**
 * @brief Zwraca maksymalną liczbę pojazdów, jakie klient typu "Silver" może wypożyczyć jednocześnie.
 * @return Maksymalna liczba pojazdów.
 */
int Silver::getMaxVehicles() const {
    return 3;
}

/**
 * @brief Oblicza zniżkę dla klienta typu "Silver".
 * @param price Cena, dla której obliczana jest zniżka.
 * @return Cena po zastosowaniu zniżki.
 */
double Silver::applyDiscount(double price) const {
    return price - 6;
}

/**
 * @brief Pobiera informacje o typie klienta.
 * @return Informacje o typie klienta.
 */
std::string Silver::getInfo() const {
    return "Silver";
}

// Gold
/**
 * @brief Zwraca maksymalną liczbę pojazdów, jakie klient typu "Gold" może wypożyczyć jednocześnie.
 * @return Maksymalna liczba pojazdów.
 */
int Gold::getMaxVehicles() const {
    return 4;
}

/**
 * @brief Oblicza zniżkę dla klienta typu "Gold".
 * @param price Cena, dla której obliczana jest zniżka.
 * @return Cena po zastosowaniu zniżki.
 */
double Gold::applyDiscount(double price) const {
    return price * 0.95;
}

/**
 * @brief Pobiera informacje o typie klienta.
 * @return Informacje o typie klienta.
 */
std::string Gold::getInfo() const {
    return "Gold";
}

// Platinum
/**
 * @brief Zwraca maksymalną liczbę pojazdów, jakie klient typu "Platinum" może wypożyczyć jednocześnie.
 * @return Maksymalna liczba pojazdów.
 */
int Platinum::getMaxVehicles() const {
    return 5;
}

/**
 * @brief Oblicza zniżkę dla klienta typu "Platinum".
 * @param price Cena, dla której obliczana jest zniżka.
 * @return Cena po zastosowaniu zniżki.
 */
double Platinum::applyDiscount(double price) const {
    return price * 0.90;
}

/**
 * @brief Pobiera informacje o typie klienta.
 * @return Informacje o typie klienta.
 */
std::string Platinum::getInfo() const {
    return "Platinum";
}

// Diamond
/**
 * @brief Zwraca maksymalną liczbę pojazdów, jakie klient typu "Diamond" może wypożyczyć jednocześnie.
 * @return Maksymalna liczba pojazdów.
 */
int Diamond::getMaxVehicles() const {
    return 10;
}

/**
 * @brief Oblicza zniżkę dla klienta typu "Diamond".
 * @param price Cena, dla której obliczana jest zniżka.
 * @return Cena po zastosowaniu zniżki.
 */
double Diamond::applyDiscount(double price) const {
    if (price <= 125) return price * 0.90;
    if (price <= 250) return price * 0.80;
    if (price <= 500) return price * 0.70;
    return price * 0.60;
}

/**
 * @brief Pobiera informacje o typie klienta.
 * @return Informacje o typie klienta.
 */
std::string Diamond::getInfo() const {
    return "Diamond";
}

