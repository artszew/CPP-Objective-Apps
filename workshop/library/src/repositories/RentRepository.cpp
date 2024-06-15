// src/repositories/RentRepository.cpp
#include "../../include/repositories/RentRepository.h"
#include "../../include/model/Rent.h"
#include <algorithm>

/**
 * @brief Zwraca wskaźnik na obiekt wypożyczenia o zadanym indeksie.
 * @param index Indeks wypożyczenia w repozytorium.
 * @return Wskaźnik na obiekt wypożyczenia lub nullptr, jeśli indeks jest nieprawidłowy.
 */
RentPtr RentRepository::get(size_t index) const {
    if (index >= rents.size()) {
        return nullptr;
    }
    return rents[index];
}

/**
 * @brief Dodaje nowy obiekt wypożyczenia do repozytorium.
 * @param rent Wskaźnik na obiekt wypożyczenia.
 */
void RentRepository::add(const RentPtr& rent) {
    if (rent != nullptr) {
        rents.push_back(rent);
    }
}

/**
 * @brief Usuwa obiekt wypożyczenia z repozytorium.
 * @param rent Wskaźnik na obiekt wypożyczenia.
 */
void RentRepository::remove(const RentPtr& rent) {
    if (rent != nullptr) {
        rents.erase(std::remove(rents.begin(), rents.end(), rent), rents.end());
    }
}

/**
 * @brief Zwraca informacje o wszystkich wypożyczeniach w repozytorium.
 * @return Informacje o wszystkich wypożyczeniach w repozytorium w formie stringu.
 */
std::string RentRepository::report() const {
    std::string report;
    for (const auto& rent : rents) {
        report += rent->getInfo() + "\n";
    }
    return report;
}

/**
 * @brief Zwraca liczbę obiektów wypożyczenia w repozytorium.
 * @return Liczba obiektów wypożyczenia w repozytorium.
 */
size_t RentRepository::size() const {
    return rents.size();
}


std::vector<RentPtr> RentRepository::findBy(RentPredicate predicate) const {
    std::vector<RentPtr> found;
    for (const auto &rent : rents) {
        if (rent != nullptr && predicate(rent)) {
            found.push_back(rent);
        }
    }
    return found;
}

std::vector<RentPtr> RentRepository::findAll() const {
    return rents;
}
