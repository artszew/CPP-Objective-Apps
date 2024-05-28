#ifndef RENT_H
#define RENT_H

#include <string>

class Client;
class Vehicle;

class Rent {
private:
    unsigned int id; /**< Identyfikator wypożyczenia */
    const Client* client; /**< Wskaźnik na klienta */
    const Vehicle* vehicle; /**< Wskaźnik na pojazd */

public:
    /**
     * @brief Konstruktor parametrowy klasy Rent.
     *
     * @param id Identyfikator wypożyczenia.
     * @param client Wskaźnik na klienta.
     * @param vehicle Wskaźnik na pojazd.
     */
    Rent(unsigned int id, const Client* client, Vehicle* vehicle);

    /**
     * @brief Metoda pobierająca informacje o wypożyczeniu.
     *
     * Zwraca informacje o wypożyczeniu, takie jak identyfikator, imię i nazwisko klienta oraz numer rejestracyjny pojazdu.
     *
     * @return Informacje o wypożyczeniu w formie łańcucha znaków.
     */
    std::string getInfo() const;

    /**
     * @brief Metoda pobierająca identyfikator wypożyczenia.
     *
     * @return Identyfikator wypożyczenia.
     */
    unsigned int getId() const;

    /**
     * @brief Metoda pobierająca wskaźnik na klienta.
     *
     * @return Wskaźnik na klienta.
     */
    const Client* getClient() const;

    /**
     * @brief Metoda pobierająca wskaźnik na pojazd.
     *
     * @return Wskaźnik na pojazd.
     */
    const Vehicle* getVehicle() const;
};

#endif

