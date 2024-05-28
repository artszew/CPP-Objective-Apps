#include "../../library/include/model/Rent.h"
#include "../../library/include/model/Client.h"
#include "../../library/include/model/Vehicle.h"
/**
 * @brief Konstruktor parametrowy klasy Rent.
 *
 * Tworzy nowy obiekt wypożyczenia z określonym identyfikatorem, klientem i pojazdem.
 *
 * @param id Identyfikator wypożyczenia.
 * @param client Wskaźnik na klienta.
 * @param vehicle Wskaźnik na pojazd.
 */
Rent::Rent(unsigned int id, const Client* client, Vehicle* vehicle)
    : id(id), client(client), vehicle(vehicle) 
    {
    if (vehicle != nullptr) {
        vehicle->setRented(true);}
    }

/**
 * @brief Metoda pobierająca informacje o wypożyczeniu.
 *
 * Zwraca informacje o wypożyczeniu, takie jak identyfikator, imię i nazwisko klienta oraz numer rejestracyjny pojazdu.
 *
 * @return Informacje o wypożyczeniu w formie łańcucha znaków.
 */
std::string Rent::getInfo() const {
    std::string info = "Rent ID: " + std::to_string(id) + "\n";
    if (client != nullptr && vehicle != nullptr) {
        info += "Client: " + client->getFirstName() + " " + client->getLastName() + "\n";
        info += "Vehicle Plate Number: " + vehicle->getPlateNumber();
    }
    return info;
}

/**
 * @brief Metoda pobierająca identyfikator wypożyczenia.
 *
 * @return Identyfikator wypożyczenia.
 */
unsigned int Rent::getId() const {
    return id;
}

/**
 * @brief Metoda pobierająca wskaźnik na klienta.
 *
 * @return Wskaźnik na klienta.
 */
const Client* Rent::getClient() const {
    return client;
}

/**
 * @brief Metoda pobierająca wskaźnik na pojazd.
 *
 * @return Wskaźnik na pojazd.
 */
const Vehicle* Rent::getVehicle() const {
    return vehicle;
}

