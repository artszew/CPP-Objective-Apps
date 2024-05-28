#include <iostream>

#include "../../library/include/model/Client.h"

using namespace std;



//Klasa klient z polami imie, nazwisko, numer pesel

Client::Client(const string& firstName, const string& lastName, const string& personalID, Address* address) : firstName(firstName), lastName(lastName), personalID(personalID),  address(address) //lista inicjalizacyjna

{}

// Metody dostępowe
    
    /**
     * @brief Pobiera informacje o kliencie.
     *
     * @param firstName lastName personalID Imię klienta Naziwsko klienta Numer personalny.
     */
string Client::getInfo() const{
    string fullInfo = "Client:\n First name: " + firstName + ", last name: " + lastName + ", personal ID: " + personalID;
    if (address != nullptr) {
        fullInfo += "Address: " + address->getInfo();
    }
    if (!currentRents.empty()) {
        fullInfo += "\nCurrent rentals:\n";
        for (const auto& rentPtr : currentRents) {
            fullInfo += rentPtr->getInfo() + "\n";
        }
    } else {
        fullInfo += "\nNo current rentals.";
    }
}

    /**
     * @brief Pobiera imię klienta.
     *
     * @param firstName Imię klienta.
     */
const string& Client::getFirstName() const {
    return firstName;

}

    /**
     * @brief Ustawia imię klienta.
     *
     * Ustawia nowe imię klienta. Jeśli nowe imię jest puste, nie zmienia wartości pola.
     *
     * @param newFirstName Nowe imię klienta.
     */
void Client::setFirstName(const string& newFirstName) {
    if (!newFirstName.empty()) { // Sprawdzenie, czy nowy napis nie jest pusty
        firstName = newFirstName;
    }
}

    /**
     * @brief Pobiera nazwisko klienta.
     *
     * @param lastName Nazwisko klienta.
     */
const string& Client::getLastName() const {
    return lastName;
}

    /**
     * @brief Ustawia nazwisko klienta.
     *
     * Ustawia nowe nazwisko klienta. Jeśli nowe nazwisko jest puste, nie zmienia wartości pola.
     *
     * @param newLastName Nowe nazwisko klienta.
     */
void Client::setLastName(const string& newLastName) {
    if (!newLastName.empty()) { // Sprawdzenie, czy nowy napis nie jest pusty
        lastName = newLastName;
    }
}

    /**
     * @brief Pobiera numer personalny klienta.
     *
     * @param personalID numer personalny klienta.
     */
const string& Client::getPersonalID() const {
    return personalID;

}

    /**
     * @brief Ustawia adres klienta.
     *
     * Ustawia nowy adresklienta. Jeśli nowy adres jest pusty, nie zmienia wartości pola.
     *
     * @param newAddress Nowy adres klienta.
     */
void Client::setAddress(Address* newAddress) {
    if (newAddress != nullptr) {
        address = newAddress;
    }
}

    /**
     * @brief Pobiera numer adres klienta.
     *
     * @param address Adres klienta.
     */
Address* Client::getAddress() const {
    return address;
}

Client::~Client() {}
