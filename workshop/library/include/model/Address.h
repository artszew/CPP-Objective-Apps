/**
 * @file Address.h
 * @brief Plik zawierający deklarację klasy Address, która reprezentuje adres klienta.
 */
#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
    
    /**
     * @brief Klasa reprezentująca adres.
     *
     * Klasa ta zawiera informacje o adresie, takie jak miasto, ulica i numer domu.
     */
class Address {

private:
    std::string city; /**< Miasto */
    std::string street; /**< Ulica */
    std::string number; /**< Numer domu i ew. mieszkania */
public:
   /**
    * @brief Konstruktor parametrowy klasy adres.
    *
    * @param city miasto adresu.
    * @param street ulica adresu.
    * @param number numer domu i mieszkania.
    */
    Address(const std::string& city, const std::string& street, const std::string& number);
    
    /**
     * @brief Metoda pobierająca informacje o adresie.
     *
     * Zwraca informacje o adresie, takie jak miasto, ulica i numer domu, w formie łańcucha znaków.
     *
     * @return Informacje o adresie w formie łańcucha znaków.
     */
    std::string getInfo() const;

    /**
     * @brief Metoda ustawiająca miasto adresu
     *
     * Ustawia nowe miasto adresu. Jeśli nowy adres jest pusty, nie zmienia wartości pola.
     *
     * @param newCity nowe miasto adresu.
     */
    void setCity(const std::string& city);
    
    /**
     * @brief Metoda pobierająca miasto adresu.
     *
     * @return miasto adresu.
     */
    const std::string& getCity() const;
    
    /**
     * @brief Metoda ustawiająca nowa ulice adresu.
     *
     * Ustawia nowa ulice adresu. Jeśli nowa ulica jest pusta, nie zmienia wartości pola.
     *
     * @param newStreet Nowa ulica adresu.
     */
    void setStreet(const std::string& street);
    
    /**
     * @brief Metoda pobierająca ulicę adresu.
     *
     * @return ulica adresu.
     */
    const std::string& getStreet() const;
    
     /**
     * @brief Metoda ustawiająca nowy numer domu adresu.
     *
     * Ustawia nowy numer domu adresu. Jeśli nowy numer domu jest pusty, nie zmienia wartości pola.
     *
     * @param newStreet Nowy numer domu adresu.
     */
    void setNumber(const std::string& number);
    
    /**
     * @brief Metoda pobierająca numer domu adresu.
     *
     * @return Ulica adresu.
     */
    const std::string& getNumber() const;

    /**
     * @brief Destruktor klasy Adres.
     *
     * Niszczy obiekt klasy Adres.
     */

    ~Address();
};

#endif
