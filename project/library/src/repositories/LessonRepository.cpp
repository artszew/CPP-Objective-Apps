/**
 * @file LessonRepository.cpp
 * @brief Plik zawierający implementacje metod klasy LessonRepository, która stanowi repozytorium zajęć.
 */
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

     /**
     * @brief Znajduje zajęcia spełniające określony warunek.
     * 
     * @param predicate Predykat określający warunek do spełnienia.
     * @return Wektor wskaźników do zajęć spełniających warunek.
     */ 
std::vector<LessonPtr> LessonRepository::findBy(LessonPredicate predicate) const {
    std::vector<LessonPtr> found;
    for (const auto &lesson : lessons) {
        if (lesson != nullptr && predicate(lesson)) {
            found.push_back(lesson);
        }
    }
    return found;
}

     /**
     * @brief Pobiera wszystkich zajęć z repozytorium.
     * 
     * @return Wektor wskaźników do wszystkich zajęć.
     */
std::vector<LessonPtr> LessonRepository::findAll() const {
    return lessons;
}
