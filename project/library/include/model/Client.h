/**
 * @file Client.h
 * @brief Plik zawierający deklarację klasy Client, która reprezentuje Klienta.
 */
#ifndef CLIENT_H
#define CLIENT_H

#include <memory>
#include <string>
#include <vector>
#include "Lesson.h"
#include "ClientType.h"

/**
 * @class Lesson
 * @brief Klasa lesson, z której metod klasa Client często korzysta.
 */
class Lesson;

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
    * @param clientID Numer identyfikacyjny klienta.
    * @param schoolClass Klasa ucznia
    * @param plannedLessons Zaplanowane lekcje
    * @param clientType Typ klienta
    * @param extensionLevel Poziom rozszerzony
    */
    Client(const std::string& firstName, const int& clientID,const int& schoolClass, std::shared_ptr<ClientType> clientType,  bool extensionLevel = false);

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
     * @brief Metoda pobierająca numer id klienta.
     *
     * @return Numer id klienta.
     */
    const int& getClientID() const;
        
    /**
     * @brief Metoda pobierająca klasę klienta.
     *
     * @return Klasa klienta.
     */        
    const int& getSchoolClass() const;

    /**
     * @brief Metoda zmieniająca klasę klienta.
     *
     * @return Nowa klasa klienta.
     */    
    void setSchoolClass(const int& schoolClass);
    
    /**
    * @brief Dodaje nowe zajęcia do wektora aktualnych zajęć.
    *
    * @param lesson Wskaźnik do zajęć.
    */
    void addPlannedLesson(const std::shared_ptr<Lesson>& lesson);
    
    /**
    * @brief Usuwa dotychczasowe lekcje z wektora aktualnych lekcji.
    *
    * @param lesson Wskaźnik do wypożyczenia.
    */
    void removePlannedLesson(const std::shared_ptr<Lesson>& lesson);
    
    /**
    * @brief Zwraca wektor wskaźników do aktualnych wypożyczeń klienta.
    *
    * @return Wektor wskaźników do aktualnych wypożyczeń klienta.
    */
     std::vector<std::shared_ptr<Lesson>> getPlannedLessons() const;

    /**
     * @brief Metoda ustawiająca typ klienta.
     *
     * @param newClientType Nowy typ klienta.
     */
   void setClientType(std::shared_ptr<ClientType> newClientType);

    
    /**
    * @brief Cenę wypożyczeń klienta.
    *
    * @return Cena wypożyczeń klienta.
    */
    float applyDiscount(float price) const;
    
    /**
    * @brief Metoda sprawdzająca czy klient jest na poziomie rozszerzonym.
    *
    * @return extensionLevel Flaga określająca poziom rozszerzony.
    */
    bool isExtensionLevel() const;
    
    /**
    * @brief Metoda ustawiająca nowy poziom rozszerzeny klientowi.
    *
    * @param extensionLevel wartość określająca, czy klient jest na poziomie rozszerzonym.
    */
    void setExtensionLevel(bool newExtensionLevel);
    
    /**
    * @brief Metoda przypisująca lekcję do klienta.
    *
    * @param Wskaźnik na lekcję.
    */
    void addLesson(const std::shared_ptr<Lesson>& lesson);
        
    /**
     * @brief Destruktor klasy Client.
     *
     * Niszczy obiekt klasy Client.
     */
    ~Client();
    
private:
    std::string firstName; /**< Imię klienta */
    const int clientID; /**< Numer klienta */
    int schoolClass; /**< Klasa klienta */
    std::vector<std::shared_ptr<Lesson>> plannedLessons; /**< Zaplanowane lekcje klienta */
    std::shared_ptr<ClientType> clientType; /**< Typ (szkoła) klienta */
    bool extensionLevel; /**< Klient na poziomie rozszerzonym */
 };
#endif
