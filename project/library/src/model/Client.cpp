/**
 * @file Client.cpp
 * @brief Plik zawierający implementacje metod klasy Client, która reprezentuje Klienta.
 */
 
  /**
 * @brief Headery klas, których metody są wykorzystywane w klasie ClientType
 * @path_to Client.h 
 * @path_to typedefs.h
 */
#include <iostream>
#include "../../library/include/model/Client.h"
#include "../../library/include/typedefs.h"

   /**
    * @brief Lista inicjalizacyjna klasy Client.
    *
    * @param firstName Imię klienta.
    * @param clientID Numer identyfikacyjny klienta.
    * @param schoolClass Klasa ucznia
    * @param clientType Typ (szkoła) klienta
    * @param extensionLevel Flaga informująca o poziomie rozszerzonym
    */
Client::Client(const std::string& firstName,const int& clientID,const int& schoolClass, std::shared_ptr<ClientType> clientType,  bool extensionLevel)
    : firstName(firstName), clientID(clientID), schoolClass(schoolClass), clientType(clientType), extensionLevel(extensionLevel) {}

/**
 * @brief Pobiera informacje o kliencie.
 *
 * @param firstName lastName clientID plannedLessons clientType Imię klienta Naziwsko klienta Numer identyfikacyjny Zaplanowane lekcje Rodzaj klienta.
 */
std::string Client::getInfo() const {
    std::string fullInfo = "\nClient:\n First name: " + firstName + ", client ID: " + std::to_string(clientID) + ", school class: " + std::to_string(schoolClass);
    fullInfo += ", client type: " + clientType->getInfo();
    if (!plannedLessons.empty()) {
        fullInfo += "\nthis client's planned lessons:\n";
        for (const auto& lessonPtr : plannedLessons) {
            fullInfo += lessonPtr->getInfo() + "\n";
        }
    } else {
        fullInfo += "\nNo planned lessons.";
    }
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
    if (!newFirstName.empty()) {
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

/**
 * @brief Pobiera numer klasę klienta.
 *
 * @param schoolClass klasa klienta.
 */
const int& Client::getSchoolClass() const {
    return schoolClass;
}

/**
 * @brief Zmienia klasę klienta na nową.
 *
 * @param newSchoolClass nowa klasa klienta.
 */
void Client::setSchoolClass(const int& newSchoolClass) {
    schoolClass = newSchoolClass;
}

/**
 * @brief Pobiera listę zaplanowanych lekcji.
 *
 * @return Wektor wskaźników do zaplanowanych lekcji.
 */
std::vector<std::shared_ptr<Lesson>> Client::getPlannedLessons() const {
    return plannedLessons;
}

/**
 * @brief Dodaje lekcję do listy zaplanowanych lekcji.
 *
 * @param lesson wskaźnik do lekcji do dodania.
 */
void Client::addLesson(const std::shared_ptr<Lesson>& lesson) {
    plannedLessons.push_back(lesson);
}

/**
 * @brief Usuwa lekcję z listy zaplanowanych lekcji.
 *
 * @param lesson wskaźnik do lekcji do usunięcia.
 */
void Client::removePlannedLesson(const std::shared_ptr<Lesson>& lesson) {
    auto it = std::remove(plannedLessons.begin(), plannedLessons.end(), lesson);
    plannedLessons.erase(it, plannedLessons.end());
}

/**
 * @brief Zastosowuje rabat do ceny.
 *
 * @param price cena przed rabatem.
 * @return Cena po zastosowaniu rabatu.
 */
float Client::applyDiscount(float price) const {
    return clientType->applyDiscount(price); //delegacja do innego obiektu
}

/**
 * @brief Sprawdza, czy klient jest na poziomie rozszerzonym.
 *
 * @return True jeśli klient jest na poziomie rozszerzonym, false w przeciwnym razie.
 */
bool Client::isExtensionLevel() const {
    return extensionLevel;
}

/**
 * @brief Ustawia poziom rozszerzeny klientowi.
 *
 * @param extensionLevel wartość określająca, czy klient jest na poziomie rozszerzonym.
 */
void Client::setExtensionLevel(bool newExtensionLevel) {
    this->extensionLevel = newExtensionLevel;
}

/**
 * @brief Ustawia nowy typ klienta.
 *
 * @param newClientType wskaźnik do nowego typu klienta.
 */
void Client::setClientType(std::shared_ptr<ClientType> newClientType) {
    if (newClientType != nullptr) {
        clientType = newClientType;
    }
}

/**
* @brief Destruktor klasy Client.
*
* Niszczy obiekt klasy Client.
*/
Client::~Client() {}
