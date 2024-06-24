/**
 * @file ClientType.h
 * @brief Plik zawierający deklarację klasy ClientType, która reprezentuje typ klienta.
 */

#ifndef CLIENTTYPE_H
#define CLIENTTYPE_H

#include <string>

/**
 * @brief Klasa reprezentująca typ klienta.
 *
 * Klasa ta zawiera metody dostępowe do informacji o typie klienta.
 */
class ClientType {
public:
    /**
     * @brief Oblicza zniżkę dla klienta na podstawie ceny.
     * @param price Cena, dla której obliczana jest zniżka.
     * @return Wartość zniżki.
     */
    virtual float applyDiscount(float price) const = 0; //funkcja czysto wirtualna

    /**
     * @brief Pobiera informacje o typie klienta.
     * @return Informacje o typie klienta.
     */
    virtual std::string getInfo() const = 0; //funkcja czysto wirtualna
    
    /**
     * @brief Wirtualny destruktor dla klasy ClientType.
     */
    virtual ~ClientType() = default;
};

/**
 * @brief Klasa reprezentująca ucznia szkoły podstawowej.
 */
class PrimarySchool : public ClientType {
public:
    float applyDiscount(float price) const override;
    std::string getInfo() const override;
};

/**
 * @brief Klasa reprezentująca ucznia szkoły średniej.
 */
class SecondarySchool : public ClientType {
public:
    float applyDiscount(float price) const override;
    std::string getInfo() const override;
    
};

/**
 * @brief Klasa reprezentująca studenta.
 */
class Student : public ClientType {
public:
    float applyDiscount(float price) const override;
    std::string getInfo() const override;
};

#endif // CLIENTTYPE_H


