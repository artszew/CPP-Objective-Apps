/**
 * @file Vehicle.cpp
 * @brief Plik zawierający definicje metod klasy Vehicle, która reprezentuje pojazd.
 */
#include <iostream>
#include "../../library/include/model/Vehicle.h"
#include "../../library/include/typedefs.h"

using namespace std;

//Klasa pojazd z polami numer rejestracyjny i cena za 1 dobe wypozyczenia
Vehicle::Vehicle(const string& plateNumber, unsigned int basePrice) : plateNumber(plateNumber), basePrice(basePrice), rented(false) //lista inicjalizacyjna
{}

// Metody dostępowe

    /**
     * @brief Pobiera parametry pojazdu.
     *
     * @param plateNumber basePrice Numer rejestracyjny pojazdu Cena za 1 dobe wypozyczenia pojazdu.
     */
string Vehicle::getInfo() const{
    return "Vehicle:\n plate number: " + plateNumber + ", base price: " + std::to_string(basePrice);
}

    /**
     * @brief Pobiera numer rejestracyjny pojazdu.
     *
     * @param numer rejestracyjny pojazdu.
     */
const string& Vehicle::getPlateNumber() const {
    return plateNumber;
}
     /**
     * @brief Ustawia numer rejestracyjny pojazdu.
     *
     * Ustawia nowy numer rejestracyjny pojazdu. Jeśli nowy numer jest pusty, nie zmienia wartości pola.
     *
     * @param newPlateNumbwe Nowy numer rejestracyjny pojazdu.
     */
void Vehicle::setPlateNumber(const string& newPlateNumber) {
    if (!newPlateNumber.empty()) { // Sprawdzenie, czy nowy napis nie jest pusty
        plateNumber = newPlateNumber;
    }
}

    /**
     * @brief Pobiera cene za 1 dobe wypozyczenia pojazdu.
     *
     * @param basePrice cena za 1 dobe wypozyczenia pojazdu.
     */
 unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}

    /**
     * @brief Ustawia nowa cene za 1 dobe wypozyczenia.
     *
     * Ustawia nowa cena za 1 dobe wypozyczenia.
     *
     * @param newBasePrice Nowa cena.
     */
void Vehicle::setBasePrice(unsigned int& basePrice) {
     { 
        this->basePrice = basePrice;
    }
}

     /**
     * @brief Ustawia status wypożyczenia pojazdu.
     *
     * @param rented Flaga określająca, czy pojazd jest wypożyczony.
     */
    void Vehicle::setRented(bool rented) {
        this->rented = rented;
    }

    /**
     * @brief Sprawdza, czy pojazd jest aktualnie wypożyczony.
     *
     * @return True, jeśli pojazd jest wypożyczony, w przeciwnym razie false.
     */
    bool Vehicle::isRented() const {
        return rented;
    }
    double Vehicle::getActualRentalPrice() const {
    return static_cast<double>(basePrice);
    }
// destruktor klasy Vehicle
Vehicle::~Vehicle() {}

