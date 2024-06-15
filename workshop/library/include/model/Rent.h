/**
 * @file Rent.h
 * @brief Plik zawierający deklarację klasy Rent, która reprezentuje wypożyczenie pojazdu.
 */
#ifndef RENT_H
#define RENT_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>
#include <memory>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Client;
class Vehicle;

/**
 * @class Rent
 * @brief Klasa reprezentująca wypożyczenie pojazdu.
 */
class Rent : public std::enable_shared_from_this<Rent> {

public:
    /**
     * @brief Konstruktor parametrowy klasy Rent.
     * @param id Identyfikator wypożyczenia.
     * @param beginTime Czas rozpoczęcia wypożyczenia.
     * @param endTime Czas zakończenia wypożyczenia.
     * @param client Wskaźnik na klienta.
     * @param vehicle Wskaźnik na pojazd.
     */
    Rent(unsigned int id, const pt::ptime& beginTime, const pt::ptime& endTime, std::weak_ptr<Client> client, std::shared_ptr<Vehicle> vehicle);

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
    std::weak_ptr<Client> getClient() const;

    /**
     * @brief Zwraca wskaźnik na pojazd.
     * @return Wskaźnik na pojazd.
     */
    std::shared_ptr<Vehicle> getVehicle() const;

private:
    unsigned int id; /**< Identyfikator wypożyczenia */
    pt::ptime beginTime; /**< Czas rozpoczęcia wypożyczenia */
    pt::ptime endTime; /**< Czas zakończenia wypożyczenia */
    int rentCost; /**< Koszt wypożyczenia */
    std::weak_ptr<Client> client; /**< Wskaźnik na klienta */
     std::shared_ptr<Vehicle> vehicle; /**< Wskaźnik na pojazd */
};
#endif // RENT_H

