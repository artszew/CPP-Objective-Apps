/**
 * @file ClientRepository.h
 * @brief Plik zawierający deklarację klasy ClientRepository, która stanowi repozytorium klientów.
 */
#ifndef CLIENTREPOSITORY_H
#define CLIENTREPOSITORY_H

#include <vector>
#include <string>
#include "../typedefs.h"

/**
 * @brief Klasa reprezentująca repozytorium klientów.
 */
class ClientRepository {
private:
    std::vector<ClientPtr> clients; ///< Wektor przechowujący wskaźniki do obiektów Client
public:
     
     /**
     * @brief Pobiera klienta na określonej pozycji.
     * 
     * @param index Indeks klienta w wektorze.
     * @return Wskaźnik do klienta.
     */
    ClientPtr get(size_t index) const;
    
    /**
     * @brief Dodaje klienta do repozytorium.
     * 
     * @param client Wskaźnik do klienta do dodania.
     */
    void add(const ClientPtr& client);
    
    /**
     * @brief Usuwa klienta z repozytorium.
     * 
     * @param client Wskaźnik do klienta do usunięcia.
     */
    void remove(const ClientPtr& client);
    
    /**
     * @brief Generuje raport o wszystkich klientach w repozytorium.
     * 
     * @return String z raportem.
     */
    std::string report() const;
    
     /**
     * @brief Pobiera liczbę klientów w repozytorium.
     * 
     * @return Liczba klientów.
     */
    size_t size() const;
    
     /**
     * @brief Znajduje klientów spełniających określony warunek.
     * 
     * @param predicate Predykat określający warunek do spełnienia.
     * @return Wektor wskaźników do klientów spełniających warunek.
     */
    std::vector<ClientPtr> findBy(ClientPredicate predicate) const;
    
    /**
     * @brief Pobiera wszystkich klientów z repozytorium.
     * 
     * @return Wektor wskaźników do wszystkich klientów.
     */    
    std::vector<ClientPtr> findAll () const;
};

#endif // CLIENTREPOSITORY_H

