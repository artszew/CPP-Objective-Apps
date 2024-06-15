/**
 * @file Rent.cpp
 * @brief Plik zawierający definicje metod klasy Rent, która reprezentuje wypożyczenie pojazdu.
 */
#include "../include/model/Rent.h"
#include "../include/model/Client.h"
#include "../include/model/Vehicle.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include "typedefs.h"
#include <string>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

/**
 * @brief Konstruktor parametrowy klasy Rent.
 * @param id Identyfikator wypożyczenia.
 * @param beginTime Czas rozpoczęcia wypożyczenia.
 * @param endTime Czas zakończenia wypożyczenia.
 * @param client Wskaźnik na klienta.
 * @param vehicle Wskaźnik na pojazd.
 */
Rent::Rent(unsigned int id, const pt::ptime& beginTime, const pt::ptime& endTime, std::weak_ptr<Client> client, std::shared_ptr<Vehicle> vehicle)
        : id(id), beginTime(beginTime), endTime(endTime), rentCost(0), client(client), vehicle(vehicle) {
    if (beginTime == pt::not_a_date_time) {
        this->beginTime = pt::second_clock::local_time(); // Ustawienie czasu rozpoczęcia na czas bieżący
    }
    if (endTime != pt::not_a_date_time) {
        this->endTime = endTime;
    }
    if (vehicle != nullptr) {
        vehicle->setRented(true);
    }
}

/**
 * @brief Zwraca informacje o wypożyczeniu.
 * @return Informacje o wypożyczeniu w formie łańcucha znaków.
 */
std::string Rent::getInfo() const {
    std::string info = "Rent ID: " + std::to_string(id) + "\n";
    auto sharedClient = client.lock();
    if (sharedClient && vehicle){
        info += "Begin time: " + boost::posix_time::to_simple_string(beginTime) + "\n";
        info += "End time: " + boost::posix_time::to_simple_string(endTime) + "\n";
        info += "Rent cost: " + std::to_string(rentCost) + "\n";
        info += "Client: " + sharedClient->getFirstName() + " " + sharedClient->getLastName() + "\n";
        info += "Vehicle Plate Number: " + vehicle->getPlateNumber();
    }
    return info;
}

/**
 * @brief Zwraca liczbę dni wypożyczenia.
 * @return Liczba dni wypożyczenia.
 */
int Rent::getRentDays() const {
    if (endTime == pt::not_a_date_time || endTime < beginTime || (endTime - beginTime) < pt::minutes(1)) {
        return 0;
    } else {
        return ((endTime - beginTime).hours() / 24) + 1;
    }
}

/**
 * @brief Kończy wypożyczenie.
 * @param endTime Czas zakończenia wypożyczenia.
 */
void Rent::endRent(const pt::ptime& endTime) {
    if (endTime == pt::not_a_date_time) {
        this->endTime = pt::second_clock::local_time();
    } else if (endTime < beginTime) {
        this->endTime = beginTime;
    } else {
        this->endTime = endTime;
    }

    this->getRentDays();
    if (this->getRentDays() > 0 && vehicle) {
        this->rentCost = this->getRentDays() * vehicle->getBasePrice();
    } else {
        this->rentCost = 0;
    }

    if (vehicle) {
        vehicle->setRented(false);
    }
    auto sharedClient = client.lock();
    if (sharedClient) {
        sharedClient->removeCurrentRent(shared_from_this());
    }
}

/**
 * @brief Zwraca identyfikator wypożyczenia.
 * @return Identyfikator wypożyczenia.
 */
unsigned int Rent::getId() const {
    return id;
}

/**
 * @brief Zwraca wskaźnik na klienta.
 * @return Wskaźnik na klienta.
 */
std::weak_ptr<Client> Rent::getClient() const {
    return client;
}

/**
 * @brief Zwraca wskaźnik na pojazd.
 * @return Wskaźnik na pojazd.
 */
std::shared_ptr<Vehicle> Rent::getVehicle() const {
    return vehicle;
}

/**
 * @brief Zwraca koszt wypożyczenia.
 * @return Koszt wypożyczenia.
 */
int Rent::getRentCost() const {
    return rentCost;
}

