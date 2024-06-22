// src/repositories/LessonRepository.cpp
#include "../../include/repositories/LessonRepository.h"
#include "../../include/model/Lesson.h"
#include <algorithm>

/**
 * @brief Zwraca wskaźnik na obiekt wypożyczenia o zadanym indeksie.
 * @param index Indeks wypożyczenia w repozytorium.
 * @return Wskaźnik na obiekt wypożyczenia lub nullptr, jeśli indeks jest nieprawidłowy.
 */
LessonPtr LessonRepository::get(size_t index) const {
    if (index >= lessons.size()) {
        return nullptr;
    }
    return lessons[index];
}

/**
 * @brief Dodaje nowy obiekt wypożyczenia do repozytorium.
 * @param rent Wskaźnik na obiekt wypożyczenia.
 */
void LessonRepository::add(const LessonPtr& lesson) {
    if (lesson != nullptr) {
        lessons.push_back(lesson);
    }
}

/**
 * @brief Usuwa obiekt wypożyczenia z repozytorium.
 * @param rent Wskaźnik na obiekt wypożyczenia.
 */
void LessonRepository::remove(const LessonPtr& lesson) {
    if (lesson != nullptr) {
        lessons.erase(std::remove(lessons.begin(), lessons.end(), lesson), lessons.end());
    }
}

/**
 * @brief Zwraca informacje o wszystkich wypożyczeniach w repozytorium.
 * @return Informacje o wszystkich wypożyczeniach w repozytorium w formie stringu.
 */
std::string LessonRepository::report() const {
    std::string report;
    for (const auto& lesson : lessons) {
        report += lesson->getInfo() + "\n";
    }
    return report;
}

/**
 * @brief Zwraca liczbę obiektów wypożyczenia w repozytorium.
 * @return Liczba obiektów wypożyczenia w repozytorium.
 */
size_t LessonRepository::size() const {
    return lessons.size();
}


std::vector<LessonPtr> LessonRepository::findBy(LessonPredicate predicate) const {
    std::vector<LessonPtr> found;
    for (const auto &lesson : lessons) {
        if (lesson != nullptr && predicate(lesson)) {
            found.push_back(lesson);
        }
    }
    return found;
}

std::vector<LessonPtr> LessonRepository::findAll() const {
    return lessons;
}
