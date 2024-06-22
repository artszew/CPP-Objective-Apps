/**
 * @file Client.cpp
 * @brief Plik zawierający definicje metod klasy Client, która reprezentuje Klienta.
 */
#include <iostream>
#include "../../library/include/model/Client.h"
#include "../../library/include/typedefs.h"

//Klasa klient z polami imie, nazwisko, numer pesel

Client::Client(const std::string& firstName,const int& clientID,const int& schoolClass, std::shared_ptr<ClientType> clientType)
    : firstName(firstName), clientID(clientID), schoolClass(schoolClass), clientType(clientType) {} // lista inicjalizacyjna

// Metody dostępowe

/**
 * @brief Pobiera informacje o kliencie.
 *
 * @param firstName lastName personalID Imię klienta Naziwsko klienta Numer personalny.
 */
std::string Client::getInfo() const {
    std::string fullInfo = "Client:\n First name: " + firstName + ", client ID: " + std::to_string(clientID) + ", school class: " + std::to_string(schoolClass);
    if (!plannedLessons.empty()) {
        fullInfo += "\nPlanned lessons:\n";
        for (const auto& lessonPtr : plannedLessons) {
            fullInfo += lessonPtr->getInfo() + "\n";
        }
    } else {
        fullInfo += "\nNo planned lessons.";
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
 * @brief Pobiera numer id klienta.
 *
 * @param clientID numer id klienta.
 */
const int& Client::getClientID() const {
    return clientID;
}


const int& Client::getSchoolClass() const {
    return schoolClass;
}

void Client::setSchoolClass(const int& newSchoolClass) {
    schoolClass = newSchoolClass;
}

std::vector<std::shared_ptr<Lesson>> Client::getPlannedLessons() const {
    return plannedLessons;
}

void Client::addLesson(const std::shared_ptr<Lesson>& lesson) {
    plannedLessons.push_back(lesson);
}

void Client::removePlannedLesson(const std::shared_ptr<Lesson>& lesson) {
    auto it = std::remove(plannedLessons.begin(), plannedLessons.end(), lesson);
    plannedLessons.erase(it, plannedLessons.end());
}

std::string Client::getClientType() const{
	return clientType->getInfo();
}

float Client::applyDiscount(float price) const {
    return clientType->applyDiscount(price);
}

void Client::setClientType(std::shared_ptr<ClientType> newClientType) {
    if (newClientType != nullptr) {
        clientType = newClientType;
    }
}

Client::~Client() {}

