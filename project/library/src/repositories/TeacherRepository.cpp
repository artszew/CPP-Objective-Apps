// src/repositories/TeacherRepository.cpp
#include "../../include/repositories/TeacherRepository.h"
#include "../../include/model/Teacher.h"
#include <algorithm>

/**
 * @brief Zwraca wskaźnik na obiekt pojazdu o zadanym indeksie.
 * @param index Indeks pojazdu w repozytorium.
 * @return Wskaźnik na obiekt pojazdu lub nullptr, jeśli indeks jest nieprawidłowy.
 */
TeacherPtr TeacherRepository::get(size_t index) const {
    if (index >= teachers.size()) {
        return nullptr;
    }
    return teachers[index];
}

/**
 * @brief Dodaje nowy obiekt pojazdu do repozytorium.
 * @param vehicle Wskaźnik na obiekt pojazdu.
 */
void TeacherRepository::add(const TeacherPtr& teacher) {
    if (teacher != nullptr) {
        teachers.push_back(teacher);
    }
}

/**
 * @brief Usuwa obiekt pojazdu z repozytorium.
 * @param vehicle Wskaźnik na obiekt pojazdu.
 */
void TeacherRepository::remove(const TeacherPtr& teacher) {
    if (teacher != nullptr) {
        teachers.erase(std::remove(teachers.begin(), teachers.end(), teacher), teachers.end());
    }
}

/**
 * @brief Zwraca informacje o wszystkich pojazdach w repozytorium.
 * @return Informacje o wszystkich pojazdach w repozytorium w formie stringu.
 */
std::string TeacherRepository::report() const {
    std::string report;
    for (const auto& teacher : teachers) {
        report += teacher->getInfo() + "\n";
    }
    return report;
}

/**
 * @brief Zwraca liczbę obiektów pojazdu w repozytorium.
 * @return Liczba obiektów pojazdu w repozytorium.
 */
size_t TeacherRepository::size() const {
    return teachers.size();
}

std::vector<TeacherPtr> TeacherRepository::findBy(TeacherPredicate predicate) const {
    std::vector<TeacherPtr> found;
    for (const auto &teacher : teachers) {
        if (teacher != nullptr && predicate(teacher)) {
            found.push_back(teacher);
        }
    }
    return found;
}

std::vector<TeacherPtr> TeacherRepository::findAll() const {
    return teachers;
}

