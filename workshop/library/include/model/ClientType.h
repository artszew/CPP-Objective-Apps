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
     * @brief Pobiera maksymalną liczbę pojazdów, które klient może wypożyczyć jednocześnie.
     * @return Maksymalna liczba pojazdów.
     */
    virtual int getMaxVehicles() const = 0;

    /**
     * @brief Oblicza zniżkę dla klienta na podstawie ceny.
     * @param price Cena, dla której obliczana jest zniżka.
     * @return Wartość zniżki.
     */
    virtual double applyDiscount(double price) const = 0;

    /**
     * @brief Pobiera informacje o typie klienta.
     * @return Informacje o typie klienta.
     */
    virtual std::string getInfo() const = 0;

    /**
     * @brief Wirtualny destruktor dla klasy ClientType.
     */
    virtual ~ClientType() = default;
};

/**
 * @brief Klasa reprezentująca domyślny typ klienta.
 */
class Default : public ClientType {
public:
    int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    std::string getInfo() const override;
};

/**
 * @brief Klasa reprezentująca typ klienta "Bronze".
 */
class Bronze : public ClientType {
public:
    int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    std::string getInfo() const override;
};

/**
 * @brief Klasa reprezentująca typ klienta "Silver".
 */
class Silver : public ClientType {
public:
    int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    std::string getInfo() const override;
};

/**
 * @brief Klasa reprezentująca typ klienta "Gold".
 */
class Gold : public ClientType {
public:
    int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    std::string getInfo() const override;
};

/**
 * @brief Klasa reprezentująca typ klienta "Platinum".
 */
class Platinum : public ClientType {
public:
    int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    std::string getInfo() const override;
};

/**
 * @brief Klasa reprezentująca typ klienta "Diamond".
 */
class Diamond : public ClientType {
public:
    int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    std::string getInfo() const override;
};

#endif // CLIENTTYPE_H

