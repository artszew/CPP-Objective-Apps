/**
 * @file Individual.h
 * @brief Plik nagłówkowy zawierający definicje metod klasy Individual, która reprezentuje zajęcia indywidualne.
 */
#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
 
 /**
 * @brief Headery klas, których metody są wykorzystywane w klasie GroupCourse
 * @path_to Lesson.h
 */
#include "Lesson.h"

/**
 * @brief Klasa reprezentująca lekcje indywidualne, dziedzicząca po klasie Lesson.
 */
class Individual : public Lesson {
private:
    bool firstLesson; ///< Flaga określająca, czy są to pierwsze zajęcia ucznia z nauczycielem.
    bool atClientHome; ///< Flaga określająca, czy zajęcia odbywają się w domu klienta.

public:
    /**
     * @brief Konstruktor parametrowy klasy Individual.
     *
     * @param lessonID Identyfikator lekcji.
     * @param beginDateAndTime Data i czas rozpoczęcia lekcji.
     * @param duration Czas trwania lekcji (w minutach).
     * @param subject Przedmiot lekcji.
     * @param client Wskaźnik na klienta.
     * @param teacher Wskaźnik na nauczyciela.
     * @param firstLesson Flaga określająca, czy są to pierwsze zajęcia ucznia z nauczycielem (domyślnie false).
     * @param atClientHome Flaga określająca, czy zajęcia odbywają się w domu klienta (domyślnie false).
     */
    Individual(const int lessonID, const pt::ptime& beginDateAndTime, float duration, const std::string& subject, std::shared_ptr<Client> client, std::shared_ptr<Teacher> teacher, bool firstLesson = false, bool atClientHome = false);

    /**
    * @brief Sprawdza, czy są to pierwsze zajęcia ucznia z nauczycielem.
    * 
    * @return True jeśli są to pierwsze zajęcia, false w przeciwnym razie.
    */
    bool isFirstLesson() const;
    
    /**
    * @brief Ustawia flagę określającą, czy są to pierwsze zajęcia ucznia z nauczycielem.
    * 
    * @param firstLesson Wartość flagi.
    */
    void setFirstLesson(bool firstLesson);

    /**
    * @brief Sprawdza, czy zajęcia odbywają się w domu klienta.
    * 
    * @return True jeśli zajęcia odbywają się w domu klienta, false w przeciwnym razie.
    */
    bool isAtClientHome() const;
    
     /**
     * @brief Ustawia flagę określającą, czy zajęcia odbywają się w domu klienta.
     * 
     * @param atClientHome Wartość flagi.
     */
    void setIsAtClientHome(bool atClientHome);

     
    /**
    * @brief Oblicza cenę lekcji.
    * 
    * @return Cena lekcji po uwzględnieniu rabatów i dodatkowych opłat.
    */
    float getLessonPrice() const;

    /**
     * @brief Pobiera informacje o lekcji.
     * 
     * @return String z informacjami o lekcji.
     */
    std::string getInfo() const;
     
     /**
     * @brief Destruktor klasy Individual.
     */
    ~Individual();
};

#endif // INDIVIDUAL_H
