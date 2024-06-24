/**
 * @file Teacher.h
 * @brief Plik zawierający definicje metod klasy Teacher, która reprezentuje nauczyciela.
 */

  /**
 * @brief Headery klas, których metody są wykorzystywane w klasie Teacher
 * @path_to Teacher.h
 * @path_to typedefs.h
 */
#include <iostream>
#include "../../library/include/model/Teacher.h"
#include "../../library/include/typedefs.h"

using namespace std;

    /**
     * @brief Lista inicjalizacyjna klasy nauczyciel.
     *
     * @param firstName Imię nauczyciela.
     * @param basePrice Cena za 1 godzinę zajęć.
     * @param teacherID Identyfikator nauczyciela.
     */
Teacher::Teacher(const string& firstName, int basePrice, const int teacherID)
    : firstName(firstName), basePrice(basePrice), teacherID(teacherID){}

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
int Teacher::getBasePrice() const {
    return basePrice;
}

    /**
     * @brief Metoda ustawiająca nową cenę za 1 godzinę zajęć.
     *
     * Ustawia nową cenę za 1 godzinę zajęć. Jeśli nowa cena jest pusta, nie zmienia wartości pola.
     *
     * @param newBasePrice Nowa cena za 1 godzinę zajęć.
     */
void Teacher::setBasePrice(int newBasePrice) {
     if (newBasePrice>0){
        this->basePrice = newBasePrice;
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

/**
 * @brief Dodaje lekcję do listy zaplanowanych lekcji nauczyciela.
 *
 * @param lesson Wskaźnik do lekcji do dodania.
 */
    void Teacher::addLesson(const std::shared_ptr<Lesson>& lesson) {
    plannedLessons.push_back(lesson);
}

/**
 * @brief Pobiera listę zaplanowanych lekcji nauczyciela.
 *
 * @return Wektor wskaźników do zaplanowanych lekcji.
 */
    std::vector<std::shared_ptr<Lesson>> Teacher::getPlannedLessons() const {
    return plannedLessons;
}

/**
 * @brief Usuwa lekcję z listy zaplanowanych lekcji nauczyciela.
 *
 * @param lesson Wskaźnik do lekcji do usunięcia.
 */
   void Teacher::removePlannedLesson(const std::shared_ptr<Lesson>& lesson) {
    auto it = std::remove(plannedLessons.begin(), plannedLessons.end(), lesson);
    plannedLessons.erase(it, plannedLessons.end());
}

/**
 * @brief Destruktor klasy GroupCourse.
 */
Teacher::~Teacher() {}
