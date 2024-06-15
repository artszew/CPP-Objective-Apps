// src/repositories/ClientRepository.cpp
#include "../../include/repositories/ClientRepository.h"
#include "../../include/model/Client.h"
#include <algorithm>

/**
 * @brief Zwraca wskaźnik na obiekt klienta o zadanym indeksie.
 * @param index Indeks klienta w repozytorium.
 * @return Wskaźnik na obiekt klienta lub nullptr, jeśli indeks jest nieprawidłowy.
 */
ClientPtr ClientRepository::get(size_t index) const {
    if (index >= clients.size()) {
        return nullptr;
    }
    return clients[index];
}

/**
 * @brief Dodaje nowy obiekt klienta do repozytorium.
 * @param client Wskaźnik na obiekt klienta.
 */
void ClientRepository::add(const ClientPtr& client) {
    if (client != nullptr) {
        clients.push_back(client);
    }
}

/**
 * @brief Usuwa obiekt klienta z repozytorium.
 * @param client Wskaźnik na obiekt klienta.
 */
void ClientRepository::remove(const ClientPtr& client) {
    if (client != nullptr) {
        clients.erase(std::remove(clients.begin(), clients.end(), client), clients.end());
    }
}

/**
 * @brief Zwraca informacje o wszystkich klientach w repozytorium.
 * @return Informacje o wszystkich klientach w repozytorium w formie stringu.
 */
std::string ClientRepository::report() const {
    std::string report;
    for (const auto& client : clients) {
        report += client->getInfo() + "\n";
    }
    return report;
}

/**
 * @brief Zwraca liczbę obiektów klienta w repozytorium.
 * @return Liczba obiektów klienta w repozytorium.
 */
size_t ClientRepository::size() const {
    return clients.size();
}


std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) const {
    std::vector<ClientPtr> found;
    for (const auto &client : clients) {
        if (client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    }
    return found;
}

std::vector<ClientPtr> ClientRepository::findAll() const {
    return clients;
}
