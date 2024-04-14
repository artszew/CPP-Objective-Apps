#include <iostream>

#include "../../library/include/model/Client.h"

using namespace std;



//Klasa klient z polami imie, nazwisko, numer pesel

Client::Client(const string& firstName, const string& lastName, const string& personalID) : firstName(firstName), lastName(lastName), personalID(personalID) //lista inicjalizacyjna

{}



// Metody dostępowe

string Client::getInfo() const{

    return "Client:\n First name: " + firstName + ", last name: " + lastName + ", personal ID: " + personalID;

}



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



const string& Client::getPersonalID() const {

    return personalID;

}



Client::~Client() {}

