/**
 * @file Vehicle.h
 * @brief Plik zawierający deklarację klasy Vehicle, która reprezentuje pojazd.
 */
#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

/**
 * @brief Klasa reprezentująca pojazd.
 *
 * Klasa ta zawiera informacje o pojeździe, takie jak numer rejestracyjny i cena za 1 dobę wypożyczenia.
 */
class Vehicle {
private:
    std::string plateNumber; /**< Numer rejestracyjny */
    unsigned int basePrice; /**< Cena za 1 dobę wypożyczenia */
    bool rented; /**< Flaga określająca, czy pojazd jest aktualnie wypożyczony */

public:
    /**
     * @brief Konstruktor parametrowy klasy pojazd.
     *
     * @param plateNumber Numer rejestracyjny pojazdu.
     * @param basePrice Cena za 1 dobę wypożyczenia pojazdu.
     * @param rented Flaga określająca, czy pojazd jest aktualnie wypożyczony.
     */
    Vehicle(const std::string& plateNumber, unsigned int basePrice);
    ~Vehicle();
    
    /**
     * @brief Metoda pobierająca informacje o pojeździe.
     *
     * Zwraca informacje o pojeździe, takie jak numer rejestracyjny i cena za 1 dobę wypożyczenia w formie łańcucha znaków.
     *
     * @return Informacje o pojeździe w formie łańcucha znaków.
     */
    std::string getInfo() const;

    /**
     * @brief Metoda ustawiająca numer rejestracyjny pojazdu.
     *
     * Ustawia nowy numer rejestracyjny pojazdu. Jeśli nowy numer rejestracyjny jest pusty, nie zmienia wartości pola.
     *
     * @param newPlateNumber Nowy numer rejestracyjny.
     */
    void setPlateNumber(const std::string& plateNumber);

    /**
     * @brief Metoda pobierająca numer rejestracyjny pojazdu.
     *
     * @return Numer rejestracyjny pojazdu.
     */
    const std::string& getPlateNumber() const;

    /**
     * @brief Metoda ustawiająca nową cenę za 1 dobę wypożyczenia pojazdu.
     *
     * Ustawia nową cenę za 1 dobę wypożyczenia. Jeśli nowa cena jest pusta, nie zmienia wartości pola.
     *
     * @param newBasePrice Nowa cena za 1 dobę wypożyczenia.
     */
    void setBasePrice(unsigned int& basePrice);

    /**
     * @brief Metoda pobierająca cenę za 1 dobę wypożyczenia pojazdu.
     *
     * @return Cena za 1 dobę wypożyczenia pojazdu.
     */
    unsigned int getBasePrice() const;

    /**
     * @brief Metoda ustawiająca flagę informującą o tym, czy pojazd jest aktualnie wypożyczony.
     *
     * @param rented Wartość flagi rented.
     */
     void setRented(bool rented);

    /**
     * @brief Metoda sprawdzająca, czy pojazd jest aktualnie wypożyczony.
     *
     * @return Wartość logiczna określająca, czy pojazd jest aktualnie wypożyczony.
     */
    bool isRented() const;
};

#endif

