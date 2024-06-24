/**
 * @file GroupCourse.h
 * @brief Plik zawierający definicje metod klasy GroupCourse, która reprezentuje zajęcia grupowe.
 */
 
#ifndef GROUPCOURSE_H
#define GROUPCOURSE_H
 
 /**
 * @brief Headery klas, których metody są wykorzystywane w klasie GroupCourse
 * @path_to Lesson.h
 */
#include "Lesson.h"

/**
 * @brief Wyliczenie określające liczbę członków w grupie.
 */
enum class AmountOfMembers { Two, Three, Four};

/**
 * @brief Klasa reprezentująca kurs grupowy, dziedzicząca po klasie Lesson.
 */
class GroupCourse : public Lesson {
private:
    AmountOfMembers amountOfMembers; ///< Liczba członków w grupie

public:

     /**
     * @brief Lista inicjalizacyjna klasy GroupCourse.
     *
     * @param lessonID Identyfikator lekcji.
     * @param beginDateAndTime Data i czas rozpoczęcia lekcji.
     * @param duration Czas trwania lekcji (w minutach).
     * @param subject Przedmiot lekcji.
     * @param client Wskaźnik na klienta.
     * @param teacher Wskaźnik na nauczyciela.
     * @param amountOfMembers Liczba członków w grupie.
     */
    GroupCourse(const int lessonID, const pt::ptime& beginDateAndTime, float duration, const std::string& subject, std::shared_ptr<Client> client, std::shared_ptr<Teacher> teacher, AmountOfMembers amountOfMembers);

    /**
    * @brief Pobiera cenę lekcji.
    *
    * @return Cena lekcji.
    */
    virtual float getLessonPrice() const;
    
    /**
    * @brief Pobiera liczbę członków w grupie.
    *
    * @return Liczba członków w grupie.
    */
    AmountOfMembers getAmountOfMembers(); 
    
    /**
    * @brief Konwertuje wartość AmountOfMembers na string.
    *
    * @param amountOfMembers Liczba członków w grupie.
    * @return String reprezentujący liczbę członków w grupie.
    */
    static std::string amountOfMembersToString(AmountOfMembers amountOfMembers);

    /**
    * @brief Pobiera informacje o kursie grupowym.
    *
    * @return String z informacjami o kursie grupowym.
    */
    std::string getInfo() const;

    /**
    * @brief Destruktor klasy GroupCourse.
    */
    ~GroupCourse();
};

#endif // GROUPCOURSE_H


