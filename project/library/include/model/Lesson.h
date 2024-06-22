#ifndef LESSON_H
#define LESSON_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>
#include <memory>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Client;
class Teacher;

/**
 * @class Lesson
 * @brief Klasa reprezentująca umówienie korepetycji.
 */
class Lesson : public std::enable_shared_from_this<Lesson> {
public:
    /**
     * @brief Konstruktor parametrowy klasy Lesson.
     * @param lessonID Identyfikator lekcji.
     * @param beginDateAndTime Data i czas kiedy odbędzie się lekcja.
     * @param duration Czas trwania lekcji (w minutach).
     * @param subject Przedmiot.
     * @param client Wskaźnik na ucznia.
     * @param teacher Wskaźnik na nauczyciela.
     */
    Lesson(const int lessonID, const pt::ptime& beginDateAndTime, float duration, const std::string& subject, std::shared_ptr<Client> client, std::shared_ptr<Teacher> teacher);

    /**
     * @brief Zwraca informacje o lekcji.
     * @return Informacje o lekcji w formie łańcucha znaków.
     */
    std::string getInfo() const;

    /**
     * @brief Zwraca identyfikator lekcji.
     * @return Identyfikator lekcji.
     */
    int getLessonID() const;

    /**
     * @brief Zwraca datę i czas rozpoczęcia lekcji.
     * @return Data i czas rozpoczęcia lekcji.
     */
    pt::ptime getBeginDateAndTime() const;

    /**
     * @brief Zwraca czas trwania lekcji (w minutach).
     * @return Czas trwania lekcji.
     */
    float getDuration() const;

    /**
     * @brief Zwraca przedmiot lekcji.
     * @return Przedmiot lekcji.
     */
    const std::string& getSubject() const;

    /**
     * @brief Zwraca koszt lekcji.
     * @return Koszt lekcji.
     */
    float getLessonCost() const;

    /**
     * @brief Zwraca wskaźnik na klienta.
     * @return Wskaźnik na klienta.
     */
    std::shared_ptr<Client> getClient() const;

    /**
     * @brief Zwraca wskaźnik na nauczyciela.
     * @return Wskaźnik na nauczyciela.
     */
    std::shared_ptr<Teacher> getTeacher() const;

    /**
     * @brief Ustawia datę i czas rozpoczęcia lekcji.
     * @param newBeginDateAndTime Nowa data i czas rozpoczęcia lekcji.
     */
    void setBeginDateAndTime(const pt::ptime& newBeginDateAndTime);

    /**
     * @brief Ustawia czas trwania lekcji (w minutach).
     * @param newDuration Nowy czas trwania lekcji.
     */
    void setDuration(float newDuration);

    /**
     * @brief Ustawia przedmiot lekcji.
     * @param newSubject Nowy przedmiot lekcji.
     */
    void setSubject(const std::string& newSubject);

private:
    const int lessonID; /**< Identyfikator lekcji */
    pt::ptime beginDateAndTime; /**< Data i czas rozpoczęcia zajęć */
    float duration; /**< Czas trwania zajęć w godzinach */
    std::string subject; /**< nazwa przedmiotu z którego są korepetycje */
    std::shared_ptr<Client> client; /**< Wskaźnik na klienta */
    std::shared_ptr<Teacher> teacher; /**< Wskaźnik na nauczyciela */
};

#endif // LESSON_H

