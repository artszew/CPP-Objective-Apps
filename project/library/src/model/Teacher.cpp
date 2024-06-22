/**
 * @file Teacher.h
 * @brief Plik zawierający definicje metod klasy Teacher, która reprezentuje nauczyciela.
 */
#include <iostream>
#include "../../library/include/model/Teacher.h"
#include "../../library/include/typedefs.h"

using namespace std;

//lista inicjalizacyjna
Teacher::Teacher(const string& firstName, unsigned int basePrice,const int teacherID)
    : firstName(firstName), basePrice(basePrice), teacherID(teacherID){}


// Metody dostępowe

    /**
     * @brief Pobiera parametry pojazdu.
     *
     * @param plateNumber basePrice Numer rejestracyjny pojazdu Cena za 1 dobe wypozyczenia pojazdu.
     */
std::string Teacher::getInfo() const {
    return "  First name: " + firstName + "  Base price per hour: " + std::to_string(basePrice) + " Teacher ID: " + std::to_string(teacherID);
}

    /**
     * @brief Pobiera imię nauczyciela.
     *
     * @param imie nauczyciela .
     */
const string& Teacher::getFirstName() const {
    return firstName;
}
     /**
     * @brief Ustawia imię nauczyciela.
     *
     * Ustawia imię nauczyciela. Jeśli nowe imię jest pusty, nie zmienia wartości pola.
     *
     * @param newFirstName Nowy numer rejestracyjny pojazdu.
     */
void Teacher::setFirstName(const string& newFirstName) {
    if (!newFirstName.empty()) { // Sprawdzenie, czy nowy napis nie jest pusty
        firstName = newFirstName;
    }
}

    /**
     * @brief Metoda pobierająca cenę za 1 godzinę zajęć.
     *
     * @return Cena za 1 godzinę zajęć.
     */
 unsigned int Teacher::getBasePrice() const {
    return basePrice;
}

    /**
     * @brief Metoda ustawiająca nową cenę za 1 godzinę zajęć.
     *
     * Ustawia nową cenę za 1 godzinę zajęć. Jeśli nowa cena jest pusta, nie zmienia wartości pola.
     *
     * @param newBasePrice Nowa cena za 1 godzinę zajęć.
     */
void Teacher::setBasePrice(unsigned int basePrice) {
     { 
        this->basePrice = basePrice;
    }
}

    /**
     * @brief Metoda pobierająca identyfikator nauczyciela.
     *
     * @return Identyfikator nauczyciela.
     */
 const int& Teacher::getTeacherID() const {
    return teacherID;
}

    void Teacher::addLesson(const std::shared_ptr<Lesson>& lesson) {
    plannedLessons.push_back(lesson);
}

    std::vector<std::shared_ptr<Lesson>> Teacher::getPlannedLessons() const {
    return plannedLessons;
}

   void Teacher::removePlannedLesson(const std::shared_ptr<Lesson>& lesson) {
    auto it = std::remove(plannedLessons.begin(), plannedLessons.end(), lesson);
    plannedLessons.erase(it, plannedLessons.end());
}

// destruktor klasy nauczyciel
Teacher::~Teacher() {}

