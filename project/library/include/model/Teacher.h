#ifndef TEACHER_H
#define TEACHER_H

#include <memory>
#include <string>
#include <vector>
#include "Lesson.h" // Dodano nagłówek Lesson.h dla vector plannedLessons

/**
 * @brief Klasa reprezentująca nauczyciela.
 *
 * Klasa ta zawiera informacje o nauczycielu.
 */
class Teacher : public std::enable_shared_from_this<Teacher> {

public:
    /**
     * @brief Konstruktor parametrowy klasy nauczyciel.
     *
     * @param firstName Imię nauczyciela.
     * @param basePrice Cena za 1 godzinę zajęć.
     * @param teacherID Identyfikator nauczyciela.
     * @param plannedLessons Wektor planowanych lekcji.
     */
    Teacher(const std::string& firstName, unsigned int basePrice,const int teacherID);

     ~Teacher();
        
    /**
     * @brief Metoda pobierająca informacje o nauczycielu.
     *
     * Zwraca informacje o nauczycielu, takie jak imię, cenę za 1 godzinę zajęć i identyfikator nauczyciela w formie łańcucha znaków.
     *
     * @return Informacje o nauczycielu w formie łańcucha znaków.
     */
    std::string getInfo() const;

    /**
     * @brief Metoda ustawiająca imię nauczyciela.
     *
     * Ustawia nowe imię nauczyciela. Jeśli nowe imię jest puste, to nie zmienia wartości pola.
     *
     * @param newFirstName Nowe imię.
     */
    void setFirstName(const std::string& newFirstName);

    /**
     * @brief Metoda pobierająca imię nauczyciela.
     *
     * @return Imię nauczyciela.
     */
    const std::string& getFirstName() const;

    /**
     * @brief Metoda ustawiająca nową cenę za 1 godzinę zajęć.
     *
     * Ustawia nową cenę za 1 godzinę zajęć. Jeśli nowa cena jest pusta, nie zmienia wartości pola.
     *
     * @param newBasePrice Nowa cena za 1 godzinę zajęć.
     */
    void setBasePrice(unsigned int newBasePrice);

    /**
     * @brief Metoda pobierająca cenę za 1 godzinę zajęć.
     *
     * @return Cena za 1 godzinę zajęć.
     */
    unsigned int getBasePrice() const;

    /**
     * @brief Metoda pobierająca identyfikator nauczyciela.
     *
     * @return Identyfikator nauczyciela.
     */
    const int& getTeacherID() const;

    void addLesson(const std::shared_ptr<Lesson>& lesson);
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
private:
    std::string firstName; /**< Imię nauczyciela */
    unsigned int basePrice; /**< Cena za 1 podstawową godzinę zajęć */
    const int teacherID; /**< Identyfikator nauczyciela */
    std::vector<std::shared_ptr<Lesson>> plannedLessons; /**< Wektor planowanych lekcji */
};

#endif // TEACHER_H

