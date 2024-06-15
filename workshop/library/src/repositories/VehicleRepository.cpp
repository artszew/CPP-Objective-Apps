// src/repositories/VehicleRepository.cpp
#include "../../include/repositories/VehicleRepository.h"
#include "../../include/model/Vehicle.h"
#include <algorithm>

/**
 * @brief Zwraca wskaźnik na obiekt pojazdu o zadanym indeksie.
 * @param index Indeks pojazdu w repozytorium.
 * @return Wskaźnik na obiekt pojazdu lub nullptr, jeśli indeks jest nieprawidłowy.
 */
VehiclePtr VehicleRepository::get(size_t index) const {
    if (index >= vehicles.size()) {
        return nullptr;
    }
    return vehicles[index];
}

/**
 * @brief Dodaje nowy obiekt pojazdu do repozytorium.
 * @param vehicle Wskaźnik na obiekt pojazdu.
 */
void VehicleRepository::add(const VehiclePtr& vehicle) {
    if (vehicle != nullptr) {
        vehicles.push_back(vehicle);
    }
}

/**
 * @brief Usuwa obiekt pojazdu z repozytorium.
 * @param vehicle Wskaźnik na obiekt pojazdu.
 */
void VehicleRepository::remove(const VehiclePtr& vehicle) {
    if (vehicle != nullptr) {
        vehicles.erase(std::remove(vehicles.begin(), vehicles.end(), vehicle), vehicles.end());
    }
}

/**
 * @brief Zwraca informacje o wszystkich pojazdach w repozytorium.
 * @return Informacje o wszystkich pojazdach w repozytorium w formie stringu.
 */
std::string VehicleRepository::report() const {
    std::string report;
    for (const auto& vehicle : vehicles) {
        report += vehicle->getInfo() + "\n";
    }
    return report;
}

/**
 * @brief Zwraca liczbę obiektów pojazdu w repozytorium.
 * @return Liczba obiektów pojazdu w repozytorium.
 */
size_t VehicleRepository::size() const {
    return vehicles.size();
}

std::vector<VehiclePtr> VehicleRepository::findBy(VehiclePredicate predicate) const {
    std::vector<VehiclePtr> found;
    for (const auto &vehicle : vehicles) {
        if (vehicle != nullptr && predicate(vehicle)) {
            found.push_back(vehicle);
        }
    }
    return found;
}

std::vector<VehiclePtr> VehicleRepository::findAll() const {
    return vehicles;
}

