/**
 * @file Rent.h
 * @brief Plik zawierający deklarację klasy Rent, która reprezentuje wypożyczenie pojazdu.
 */
#ifndef RENT_H
#define RENT_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Client;
class Vehicle;

/**
 * @class Rent
 * @brief Klasa reprezentująca wypożyczenie pojazdu.
 */
class Rent {
private:
    unsigned int id; /**< Identyfikator wypożyczenia */
    pt::ptime beginTime; /**< Czas rozpoczęcia wypożyczenia */
    pt::ptime endTime; /**< Czas zakończenia wypożyczenia */
    int rentCost; /**< Koszt wypożyczenia */
    Client* client; /**< Wskaźnik na klienta */
    Vehicle* vehicle; /**< Wskaźnik na pojazd */

public:
    /**
     * @brief Konstruktor parametrowy klasy Rent.
     * @param id Identyfikator wypożyczenia.
     * @param beginTime Czas rozpoczęcia wypożyczenia.
     * @param endTime Czas zakończenia wypożyczenia.
     * @param client Wskaźnik na klienta.
     * @param vehicle Wskaźnik na pojazd.
     */
    Rent(unsigned int id, const pt::ptime& beginTime, const pt::ptime& endTime, Client* client, Vehicle* vehicle);

    /**
     * @brief Zwraca informacje o wypożyczeniu.
     * @return Informacje o wypożyczeniu w formie łańcucha znaków.
     */
    std::string getInfo() const;

    /**
     * @brief Zwraca identyfikator wypożyczenia.
     * @return Identyfikator wypożyczenia.
     */
    unsigned int getId() const;

    /**
     * @brief Zwraca liczbę dni wypożyczenia.
     * @return Liczba dni wypożyczenia.
     */
    int getRentDays() const;

    /**
     * @brief Kończy wypożyczenie.
     * @param endTime Czas zakończenia wypożyczenia.
     */
    void endRent(const pt::ptime& endTime);

    /**
     * @brief Zwraca koszt wypożyczenia.
     * @return Koszt wypożyczenia.
     */
    int getRentCost() const;

    /**
     * @brief Zwraca wskaźnik na klienta.
     * @return Wskaźnik na klienta.
     */
    const Client* getClient() const;

    /**
     * @brief Zwraca wskaźnik na pojazd.
     * @return Wskaźnik na pojazd.
     */
    const Vehicle* getVehicle() const;
};

#endif // RENT_H

