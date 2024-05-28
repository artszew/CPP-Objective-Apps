/**
 * @file Client.h
 * @brief Plik zawierający deklarację klasy Client, która reprezentuje Klienta.
 */
#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Address.h"
#include "Rent.h"

class Rent;

    /**
     * @brief Klasa reprezentująca klienta.
     *
     * Klasa ta zawiera informacje o kliencie, takie jak imię, nazwisko i numer personalny.
     */
class Client {
private:
    std::string firstName; /**< Imię klienta */
    std::string lastName; /**< Nazwisko klienta */
    const std::string personalID; /**< Numer personalny klienta */
    Address* address; //** <Wskaznik na adres */
    std::vector<Rent*> currentRents; /**< Wektor wskaźników do obiektów Rent */
    
public:
   /**
    * @brief Konstruktor parametrowy klasy Client.
    *
    * @param firstName Imię klienta.
    * @param lastName Nazwisko klienta.
    * @param personalID Numer personalny klienta.
    * @param address Adres klienta
    * @param currentRents Wypozyczenia klienta
    */

    Client(const std::string& firstName, const std::string& lastName, const std::string& personalID, Address* address);

    /**
     * @brief Metoda pobierająca informacje o kliencie.
     *
     * Zwraca informacje o kliencie, takie jak imię, nazwisko i numer personalny, w formie łańcucha znaków.
     *
     * @return Informacje o kliencie w formie łańcucha znaków.
     */
    std::string getInfo() const;

    /**
     * @brief Metoda ustawiająca imię klienta.
     *
     * Ustawia nowe imię klienta. Jeśli nowe imię jest puste, nie zmienia wartości pola.
     *
     * @param newFirstName Nowe imię klienta.
     */
    void setFirstName(const std::string& firstName);

    /**
     * @brief Metoda pobierająca imię klienta.
     *
     * @return Imię klienta.
     */
    const std::string& getFirstName() const;



    /**
     * @brief Metoda ustawiająca nazwisko klienta.
     *
     * Ustawia nowe nazwisko klienta. Jeśli nowe nazwisko jest puste, nie zmienia wartości pola.
     *
     * @param newLastName Nowe nazwisko klienta.
     */
    void setLastName(const std::string& lastName);

    /**
     * @brief Metoda pobierająca nazwisko klienta.
     *
     * @return Nazwisko klienta.
     */
    const std::string& getLastName() const;

    /**
     * @brief Metoda pobierająca numer personalny klienta.
     *
     * @return Numer personalny klienta.
     */
    const std::string& getPersonalID() const;


    void setAddress(Address* newAddress);

    Address* getAddress() const;
	
   void addRent(Rent* rent);

    /**
    * @brief Dodaje nowe wypożyczenie do wektora aktualnych wypożyczeń.
    *
    * @param rent Wskaźnik do wypożyczenia.
    */
    void addCurrentRent(Rent* rent);
    
    /**
    * @brief Usuwa dotychczasowe wypożyczenie z wektora aktualnych wypożyczeń.
    *
    * @param rent Wskaźnik do wypożyczenia.
    */
    void removeCurrentRent(Rent* rent);
    
    /**
    * @brief Zwraca wektor wskaźników do aktualnych wypożyczeń klienta.
    *
    * @return Wektor wskaźników do aktualnych wypożyczeń klienta.
    */
    std::vector<Rent*> getCurrentRents() const;
    
    /**
     * @brief Destruktor klasy Client.
     *
     * Niszczy obiekt klasy Client.
     */
    ~Client();

};

#endif
