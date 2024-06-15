/**
 * @file Client.h
 * @brief Plik zawierający deklarację klasy Client, która reprezentuje Klienta.
 */
#ifndef CLIENT_H
#define CLIENT_H
#include <memory>
#include <string>
#include <vector>
#include "Address.h"
#include "Rent.h"
#include "ClientType.h"

class Rent;

    /**
     * @brief Klasa reprezentująca klienta.
     *
     * Klasa ta zawiera informacje o kliencie, takie jak imię, nazwisko i numer personalny.
     */
class Client : public std::enable_shared_from_this<Client> {
public:

   /**
    * @brief Konstruktor parametrowy klasy Client.
    *
    * @param firstName Imię klienta.
    * @param lastName Nazwisko klienta.
    * @param personalID Numer personalny klienta.
    * @param address Adres klienta
    * @param currentRents Wypozyczenia klienta
    * @param clientType Typ klienta
    */

    Client(const std::string& firstName, const std::string& lastName, const std::string& personalID, std::shared_ptr<Address> address, std::shared_ptr<ClientType> clientType);

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

    /**
     * @brief Metoda ustawiająca adres klienta.
     *
     * Ustawia nowy adres klienta. Jeśli nowy adres jest puste, nie zmienia wartości pola.
     *
     * @param newAddress Nowy adres klienta.
     */
    void setAddress(std::shared_ptr<Address> newAddress);

    /**
     * @brief Metoda pobierająca adres klienta.
     *
     * @return Adres klienta.
     */
     std::shared_ptr<Address> getAddress() const;
	

    /**
    * @brief Dodaje nowe wypożyczenie do wektora aktualnych wypożyczeń.
    *
    * @param rent Wskaźnik do wypożyczenia.
    */
    void addCurrentRent(const std::shared_ptr<Rent>& rent);
    
    /**
    * @brief Usuwa dotychczasowe wypożyczenie z wektora aktualnych wypożyczeń.
    *
    * @param rent Wskaźnik do wypożyczenia.
    */
    void removeCurrentRent(const std::shared_ptr<Rent>& rent);
    
    /**
    * @brief Zwraca wektor wskaźników do aktualnych wypożyczeń klienta.
    *
    * @return Wektor wskaźników do aktualnych wypożyczeń klienta.
    */
     std::vector<std::shared_ptr<Rent>> getCurrentRents() const;
    
    /**
     * @brief Metoda ustawiająca typ klienta.
     *
     * Ustawia nowy typ klienta.
     *
     * @param newClientType Nowy typ klienta.
     */
   void setClientType(std::shared_ptr<ClientType> newClientType);
    
    /**
    * @brief Zwraca maksymalną ilość pojazdów klienta danego typu.
    *
    * @return Maksymalna ilość pojazdów do wypożyczenia.
    */
    int getMaxVehicles() const;
    
    /**
    * @brief Cenę wypożyczeń klienta.
    *
    * @return Cena wypożyczeń klienta.
    */
    double applyDiscount(double price) const;
    
    void addRent(const std::shared_ptr<Rent>& rent);
    
    /**
     * @brief Destruktor klasy Client.
     *
     * Niszczy obiekt klasy Client.
     */
    ~Client();
private:
    std::string firstName; /**< Imię klienta */
    std::string lastName; /**< Nazwisko klienta */
    const std::string personalID; /**< Numer personalny klienta */
    std::shared_ptr<Address> address; //** <Wskaznik na adres */
     std::vector<std::shared_ptr<Rent>> currentRents; /**< Wektor wskaźników do obiektów Rent */
    std::shared_ptr<ClientType> clientType;
 };
#endif
