/**
 * @file Client.cpp
 * @brief Plik zawierający definicje metod klasy Client, która reprezentuje Klienta.
 */
#include <iostream>
#include "../../library/include/model/Client.h"
#include "../../library/include/typedefs.h"


//Klasa klient z polami imie, nazwisko, numer pesel

Client::Client(const std::string& firstName, const std::string& lastName, const std::string& personalID, std::shared_ptr<Address> address, std::shared_ptr<ClientType> clientType) : firstName(firstName), lastName(lastName), personalID(personalID), address(address), clientType(clientType) {}//lista inicjalizacyjna

// Metody dostępowe
    
    /**
     * @brief Pobiera informacje o kliencie.
     *
     * @param firstName lastName personalID Imię klienta Naziwsko klienta Numer personalny.
     */
std::string Client::getInfo() const{
    std::string fullInfo = "Client:\n First name: " + firstName + ", last name: " + lastName + ", personal ID: " + personalID;
    if (address != nullptr) {
        fullInfo += address->getInfo();
    }
    if (!currentRents.empty()) {
        fullInfo += "\nCurrent rentals:\n";
        for (const auto& rentPtr : currentRents) {
            fullInfo += rentPtr->getInfo() + "\n";
        }
    } else {
        fullInfo += "\nNo current rentals.";
    }
    fullInfo += "\nClient type: " + clientType->getInfo();
    return fullInfo;
}

    /**
     * @brief Pobiera imię klienta.
     *
     * @param firstName Imię klienta.
     */
const std::string& Client::getFirstName() const {
    return firstName;

}

    /**
     * @brief Ustawia imię klienta.
     *
     * Ustawia nowe imię klienta. Jeśli nowe imię jest puste, nie zmienia wartości pola.
     *
     * @param newFirstName Nowe imię klienta.
     */
void Client::setFirstName(const std::string& newFirstName) {
    if (!newFirstName.empty()) { // Sprawdzenie, czy nowy napis nie jest pusty
        firstName = newFirstName;
    }
}

    /**
     * @brief Pobiera nazwisko klienta.
     *
     * @param lastName Nazwisko klienta.
     */
const std::string& Client::getLastName() const {
    return lastName;
}

    /**
     * @brief Ustawia nazwisko klienta.
     *
     * Ustawia nowe nazwisko klienta. Jeśli nowe nazwisko jest puste, nie zmienia wartości pola.
     *
     * @param newLastName Nowe nazwisko klienta.
     */
void Client::setLastName(const std::string& newLastName) {
    if (!newLastName.empty()) { // Sprawdzenie, czy nowy napis nie jest pusty
        lastName = newLastName;
    }
}

    /**
     * @brief Pobiera numer personalny klienta.
     *
     * @param personalID numer personalny klienta.
     */
const std::string& Client::getPersonalID() const {
    return personalID;

}

    /**
     * @brief Ustawia adres klienta.
     *
     * Ustawia nowy adresklienta. Jeśli nowy adres jest pusty, nie zmienia wartości pola.
     *
     * @param newAddress Nowy adres klienta.
     */
void Client::setAddress(std::shared_ptr<Address> newAddress) {
    if (newAddress != nullptr) {
        address = newAddress;
    }
}


    /**
     * @brief Pobiera numer adres klienta.
     *
     * @param address Adres klienta.
     */
std::shared_ptr<Address> Client::getAddress() const {
    return address;
}

std::vector<std::shared_ptr<Rent>> Client::getCurrentRents() const {
    return currentRents;
}

void Client::addRent(const std::shared_ptr<Rent>& rent) {
    currentRents.push_back(rent);
}

void Client::addCurrentRent(const std::shared_ptr<Rent>& rent) {
    currentRents.push_back(rent);
}

void Client::removeCurrentRent(const std::shared_ptr<Rent>& rent) {
    auto it = std::remove(currentRents.begin(), currentRents.end(), rent);
    currentRents.erase(it, currentRents.end());
}

int Client::getMaxVehicles() const {
    return clientType->getMaxVehicles();
}

double Client::applyDiscount(double price) const {
    return clientType->applyDiscount(price);
}

void Client::setClientType(std::shared_ptr<ClientType> newClientType) {
    if (newClientType != nullptr) {
        clientType = newClientType;
    }
}

Client::~Client(){}
