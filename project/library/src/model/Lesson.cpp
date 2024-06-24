/**
 * @file Lesson.cpp
 * @brief Plik zawierający implementacje metod klasy Lesson, która stanowi klasę bazową dla GroupCourse i Individual.
 */
 
  /**
 * @brief Headery klas, których metody są wykorzystywane w klasie Lesson
 * @path_to Lesson.h
 * @path_to Client.h
 * @path_to Teacher.h
 * @path_to posix_time.hpp Zewnętrzna biblioteka związana z określaniem czasu
 */
#include "../include/model/Lesson.h"
#include "../include/model/Client.h"
#include "../include/model/Teacher.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

/**
 * @brief Konstruktor parametrowy klasy Lesson.
 * @param lessonID Identyfikator lekcji.
 * @param beginDateAndTime Data i czas kiedy odbędzie się lekcja.
 * @param duration Czas trwania lekcji (w minutach).
 * @param subject Przedmiot.
 * @param client Wskaźnik na ucznia.
 * @param teacher Wskaźnik na nauczyciela.
 */
Lesson::Lesson(const int lessonID, const pt::ptime& beginDateAndTime, float duration, const std::string& subject, std::shared_ptr<Client> client, std::shared_ptr<Teacher> teacher)
    : lessonID(lessonID), beginDateAndTime(beginDateAndTime), duration(duration), subject(subject), client(client), teacher(teacher) {}

/**
 * @brief Zwraca informacje o lekcji.
 * @return Informacje o lekcji w formie łańcucha znaków.
 */
std::string Lesson::getInfo() const {
    std::string info = "Lesson ID: " + std::to_string(lessonID) + "\n";
    if (client && teacher) {
        info += "Begin time: " + boost::posix_time::to_simple_string(beginDateAndTime);
        info += ", duration: " + std::to_string(duration) + " hours";
        info += ", subject: " + subject;
        info += ", client: " + client->getFirstName();
        info += ", teacher: " + teacher->getFirstName();   }
    return info;
}

/**
 * @brief Zwraca identyfikator lekcji.
 * @return Identyfikator lekcji.
 */
int Lesson::getLessonID() const {
    return lessonID;
}

/**
 * @brief Zwraca czas trwania lekcji (w minutach).
 * @return Czas trwania lekcji.
 */
float Lesson::getDuration() const {
    return duration;
}

/**
 * @brief Ustawia czas trwania lekcji (w minutach).
 * @param newDuration Nowy czas trwania lekcji.
 */
void Lesson::setDuration(float newDuration) {
    if (newDuration >= 0.5) {
    duration = newDuration;
    }
    
}

/**
 * @brief Zwraca przedmiot lekcji.
 * @return Przedmiot lekcji.
 */
const std::string& Lesson::getSubject() const {
    return subject;
}

/**
 * @brief Ustawia przedmiot lekcji.
 * @param newSubject Nowy przedmiot lekcji.
 */
void Lesson::setSubject(const std::string& newSubject) {
    if (!newSubject.empty()){
    subject = newSubject;}
}
    
/**
 * @brief Zwraca wskaźnik na klienta.
 * @return Wskaźnik na klienta.
 */
std::shared_ptr<Client> Lesson::getClient() const {
    return client;
}

/**
 * @brief Zwraca wskaźnik na nauczyciela.
 * @return Wskaźnik na nauczyciela.
 */
std::shared_ptr<Teacher> Lesson::getTeacher() const {
    return teacher;
}

/**
 * @brief Ustawia datę i czas rozpoczęcia lekcji.
 * @param newBeginDateAndTime Nowa data i czas rozpoczęcia lekcji.
 */
void Lesson::setBeginDateAndTime(const pt::ptime& newBeginDateAndTime) {
    if (newBeginDateAndTime > getBeginDateAndTime() + pt::hours(1)) {
    beginDateAndTime = newBeginDateAndTime;
    }
}

/**
 * @brief Zwraca datę i czas rozpoczęcia lekcji.
 * @return Datę i czas rozpoczęcia lekcji.
 */
pt::ptime Lesson::getBeginDateAndTime() const {
    return beginDateAndTime;
}
/**
 * @brief Destruktor klasy lekcja.
 */
Lesson::~Lesson() {} 
