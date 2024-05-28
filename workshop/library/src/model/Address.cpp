/**
 * @file Address.cpp
 * @brief Plik zawierający definicje metod klasy Address, która reprezentuje adres klienta.
 */
#include <iostream>
#include "../../library/include/model/Address.h"

using namespace std;

//Klasa adres z polami miasto, ulica i numer domu
Address::Address(const string& city, const string& street, const string& number) : city(city), street(street), number(number) //lista inicjalizacyjna
{}

// Metody dostępowe

    /**
     * @brief Pobiera parametry adresu.
     *
     * @param city street number Miasto Ulica Numer domu.
     */
string Address::getInfo() const{
    return "Address:\n City: " + city + ", street: " + street + ", number: " + number;
}

    /**
     * @brief Pobiera miasto adresu.
     *
     * @param city Miasto adresu.
     */
const string& Address::getCity() const {
    return city;
}
     /**
     * @brief Ustawia miasto adresu.
     *
     * Ustawia nowe miasto adresu. Jeśli nowe miasto jest puste, nie zmienia wartości pola.
     *
     * @param newCity Nowe miasto adresu.
     */
void Address::setCity(const string& newCity) {
    if (!newCity.empty()) { // Sprawdzenie, czy nowy napis nie jest pusty
        city = newCity;
    }
}

    /**
     * @brief Pobiera ulice adresu.
     *
     * @param street ulica adresu.
     */
const string& Address::getStreet() const {
    return street;
}

    /**
     * @brief Ustawia nowa ulice adresu.
     *
     * Ustawia nowa ulice adresu. Jeśli nowa ulica jest pusta, nie zmienia wartości pola.
     *
     * @param newCity Nowa ulica adresu.
     */
void Address::setStreet(const string& newStreet) {
    if (!newStreet.empty()) { // Sprawdzenie, czy nowy napis nie jest pusty
        street = newStreet;
    }
}

    /**
     * @brief Pobiera numer domu adresu.
     *
     * @param number numer domu adresu.
     */
const string& Address::getNumber() const {
    return number;
}

    /**
     * @brief Ustawia nowy numer adresu.
     *
     * Ustawia nowy numer domu adresu. Jeśli nowy numer jest pusty, nie zmienia wartości pola.
     *
     * @param newNumber Nowy numer domu adresu.
     */
void Address::setNumber(const string& newNumber) {
    if (!newNumber.empty()) { // Sprawdzenie, czy nowy napis nie jest pusty
        number = newNumber;
    }
}

Address::~Address() {}

